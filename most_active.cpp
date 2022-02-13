#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <deque>
#include <regex>
using namespace std;

//Test Commands
// .\most_active_cookie.exe .\cookie_log.csv -d 2018-12-08  -- CORRECT
// .\most_active_cookie.exe .\cookie_log.csv -d 2018-12-07  -- Wrong date, so no output should be there
// .\most_active_cookie.exe .\cookie_log.csv -d 2018-08-07  -- Wrong month, so no output should be there
// .\most_active_cookie.exe .\cookie_log.csv -d 1996-12-18  -- Wrong year, so no output should be there
// .\most_active_cookie.exe .\cookie_log.csv -d 2018-2-08   -- Invalid month format, error thrown on date format
// .\most_active_cookie.exe .\cookie_log.csv -d cddscdscds  -- Invalid arguments after -d, error thrown on date format
// .\most_active_cookie.exe .\cookie_log.cs -d 2018-12-08   -- Wrong data file format, error thrown on input data file format
// .\most_active_cookie.exe .\cookie_log.exe -d 1996-12-08  -- Wrong data file format, error thrown on input data file format
// .\most_active_cookie.exe cookie                          -- Wrong data file and no date, error thrown on less arguments
// .\most_active_cookie.exe                                 -- No data file and no date, error thrown on input data file format
// .\most_active_cookie.exe -d 2018-12-08                   -- No data file, error thrown on less arguments
// .\most_active_cookie.exe .\cookie_log.exe -d 96-12-8     -- Wrong data file and wrong date, error thrown on both input data file format and date format
//Test Commands end here

//declaring global variables
char *date;
vector<string> sourceData;
deque<string> processedData;


bool invalidInput(int argc,char *argv[]) {
    // Step0 : Parse command line number of arguments to check for valid input
    if (argc < 4)
    {
        fprintf(stderr, "Less number of arguments provided \n");
        return true;
    }
    else if (argc > 4)
    {
        fprintf(stderr, "Too many arguments provided \n");
        return true;
    } else {
        int n = ((string)argv[1]).length();
        if(((string)argv[1]).substr(n-4,n-1)!=".csv"){
            fprintf(stderr, "Invalid input data file \n");
        }
        return false;
    }
}

void processInput () {
    char *cookieName, *cookieTimestamp;
    unordered_map<string, int> cookieMap;
    vector<string> cookieOrder;
    int maxVal = 0;
    char *timePtr, *tempPtr;
    

    // processing the csv file and calculating the frequency of each cookie
    for (int i = 0; i < processedData.size(); i++)
    {
        cookieName = strtok((char *)processedData[i].c_str(), ",");
        cookieTimestamp = strtok(NULL, ",");
        tempPtr = strtok(cookieTimestamp, "T");
        timePtr = strtok(NULL, "T");
        if (strcmp(date, cookieTimestamp)==0)
        {
            cookieMap[(string)cookieName]++;
            if(cookieMap[(string)cookieName]==1){
                cookieOrder.push_back((string)cookieName);
            }
            maxVal = max(maxVal, cookieMap[(string)cookieName]);
        }
    }

    for (int i = 0; i < cookieOrder.size(); ++i)
        {
            if(cookieMap[cookieOrder[i]]==maxVal){
                printf("%s\n", cookieOrder[i].c_str());
            }
        }
}

//Pass command line arguments to main to get processed
int main(int argc, char *argv[])
{
    if(invalidInput(argc,argv)) {
        return 1;
    } 
    else { 
        //Step1 : checking for valid command line inputs
        for (int i = 1; i < argc; i++)
        {
            string arg = argv[i];
            if (arg == "-d")
            {
                if (i + 1 < argc)
                {
                    date = argv[++i];
                }
                else
                {
                    fprintf(stderr, "Argument missing. Please give valid input after -d\n");
                    return 1;
                }
            }
            else
            {
                sourceData.push_back(argv[i]);
            }
        }
        regex str_expr ("([12]\\d{3}-(0[1-9]|1[0-2])-(0[1-9]|[12]\\d|3[01]))");
        bool val = regex_match((string)date,str_expr);
        if(val==0){
            fprintf(stderr, "Please give valid date format after -d\n");
            return 1;
        }
        //Step1 finished
        
        // Step2 : reading csv started
        ifstream in(sourceData[0]);

        for (string row; getline(in, row);)
        {
            if (row.empty())
                continue;
            processedData.push_back(row);
        }

        in.close();
        // Step2 finished

        // Step3 : Process input data from cookie_log.csv
        processInput();
        // Step3 finished

        //Exit
        return 0;
    }
}