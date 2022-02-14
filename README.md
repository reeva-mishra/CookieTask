# CookieTask
To compile C++ file: g++ -o most_active_cookie .\most_active.cpp <br/>
To run and test program: .\most_active_cookie.exe .\cookie_log.csv -d 2018-12-08

Test Cases: (also included in the program) <br/>
1. .\most_active_cookie.exe .\cookie_log.csv -d 2018-12-08  -- CORRECT <br/>
2. .\most_active_cookie.exe .\cookie_log.csv -d 2018-12-07  -- Wrong date, so no output should be there<br/>
3. .\most_active_cookie.exe .\cookie_log.csv -d 2018-08-07  -- Wrong month, so no output should be there<br/>
4. .\most_active_cookie.exe .\cookie_log.csv -d 1996-12-18  -- Wrong year, so no output should be there<br/>
5. .\most_active_cookie.exe .\cookie_log.csv -d 2018-2-08   -- Invalid month format, error thrown on date format<br/>
6. .\most_active_cookie.exe .\cookie_log.csv -d cddscdscds  -- Invalid arguments after -d, error thrown on date format<br/>
7. .\most_active_cookie.exe .\cookie_log.cs -d 2018-12-08   -- Wrong data file format, error thrown on input data file format<br/>
8. .\most_active_cookie.exe .\cookie_log.exe -d 1996-12-08  -- Wrong data file format, error thrown on input data file format<br/>
9. .\most_active_cookie.exe cookie                          -- Wrong data file and no date, error thrown on less arguments<br/>
10. .\most_active_cookie.exe                                 -- No data file and no date, error thrown on input data file format<br/>
11. .\most_active_cookie.exe -d 2018-12-08                   -- No data file, error thrown on less arguments<br/>
12. .\most_active_cookie.exe .\cookie_log.exe -d 96-12-8     -- Wrong data file and wrong date, error thrown on both input data file format and date format<br/>
