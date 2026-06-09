```cpp
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        const int yearOffset = -1970, monthOffset = -1;
        const char* answers[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

        int dayYearMonth[130+1][12];  // 0 -> 1970 ; 1 -> 1971 ; 130->2100
        
        for(int year = 1970; year <= 2100; ++year) {
            for(int month = 1; month <= 12; ++month) {
                if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                    dayYearMonth[year+yearOffset][month+monthOffset] = 31;
                else if(month == 2) {
                    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))  // 闰年
                        dayYearMonth[year+yearOffset][month+monthOffset] = 29;
                    else
                        dayYearMonth[year+yearOffset][month+monthOffset] = 28;
                }
                else
                    dayYearMonth[year+yearOffset][month+monthOffset] = 30;
            }
        }

        const int originDay = 4, originMonth = 1, originYear = 1970;  // 1970-01-04 is a Sunday
        int disToOrigin = 0;
        for(int y = originYear; y <= year; ++ y) {
            if(y != year){
                for(int m = 1; m <= 12; ++m)
                    disToOrigin += dayYearMonth[y+yearOffset][m+monthOffset];
            }
            else {
                for(int m = 1; m < month; ++m)
                    disToOrigin += dayYearMonth[y+yearOffset][m+monthOffset];
                disToOrigin += day - originDay;
            }
        }

        return answers[disToOrigin % 7];
    }
};
// @lc code=end

int main() {
    Solution ins = Solution();
    cout << 
    ins.dayOfTheWeek(4, 1, 1970) << endl <<
    ins.dayOfTheWeek(5, 1, 1970) << endl <<
    ins.dayOfTheWeek(6, 1, 1970) << endl <<

    ins.dayOfTheWeek(11, 1, 1970) << endl <<
    ins.dayOfTheWeek(12, 1, 1970) << endl <<
    ins.dayOfTheWeek(13, 1, 1970) << endl ;

    cout << endl;

    cout << 
    ins.dayOfTheWeek(4, 12, 1970) << endl <<
    ins.dayOfTheWeek(5, 12, 1970) << endl <<
    ins.dayOfTheWeek(6, 12, 1970) << endl <<

    ins.dayOfTheWeek(11, 12, 1970) << endl <<
    ins.dayOfTheWeek(12, 12, 1970) << endl <<
    ins.dayOfTheWeek(13, 12, 1970) << endl ;

    cout << endl;

    cout << 
    ins.dayOfTheWeek(11, 2, 2020) << endl;
    return 0;
}
```
