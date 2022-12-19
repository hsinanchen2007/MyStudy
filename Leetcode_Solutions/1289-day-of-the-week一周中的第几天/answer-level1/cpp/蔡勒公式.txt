### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
const vector<string> w= { "Monday", "Tuesday", "Wednesday",
                             "Thursday", "Friday", "Saturday","Sunday"};   
    string dayOfTheWeek(int day, int month, int year) {
    if (month == 1) {
            month = 13;
            year--;
    }
    if (month == 2) {
        month = 14;
        year--;
    }
    int week = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;

    return w[week];
    }
};
```