### 解题思路
模拟日期添加

### 代码

```cpp
class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(getDay(date1) - getDay(date2));
    }
    
    int monthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    bool isLeap(int year) {
        return year % 4 == 0 && year % 100 || year % 400 == 0;
    }
    
    int getDay(string date) {
        int year, month, day;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        int ret = 0;
        for (int i = 1971; i < year; i++) {
            ret += 365 + (isLeap(i) ? 1 : 0);
        }
        for (int i = 1; i < month; i++) {
            if (i == 2) ret += monthDay[2] + (isLeap(year) ? 1 : 0);
            else ret += monthDay[i];
        }
        return ret + day;
    }
};
```