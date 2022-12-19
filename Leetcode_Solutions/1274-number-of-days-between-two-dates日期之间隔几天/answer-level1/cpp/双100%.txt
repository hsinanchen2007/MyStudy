### 解题思路

计算与某个起始时间点相隔的天数，然后做相减即可。
需要注意闰年的判断，整百年被400整除，非整百年被4整除即可。
### 代码

```cpp
static int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class Solution {
private:
    bool isLeap(int year) {
        return year % 100 && year % 4 == 0 || year % 400 == 0;
    }
    int getDay(string date) {
        int year, month, day;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        int days = 0;
        for (int y = 1971; y < year; y ++) {
            days += isLeap(y) + 365;
        }
        for (int m = 1; m < month; m ++) {
            if (m == 2) days += isLeap(year) + 28;
            else
                days += months[m];
        }
        return days + day;

    }
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(getDay(date1) - getDay(date2));
    }
};
```