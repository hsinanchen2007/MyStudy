提取出年月日，根据不同月份累加天数即可

代码：
```
class Solution {
public:
    int dayOfYear(string date) {
        int year = 0, month = 0, day = 0;
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 0; i < 4; i++)
            year = year * 10 + (int)date[i] - 48;
        for (int i = 5; i < 7; i++)
            month = month * 10 + (int)date[i] - 48;
        for (int i = 8; i < 10; i++)
            day = day * 10 + (int)date[i] - 48;
        if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
            days[1]++;
        int ans = day;
        for (int i = 0; i < month - 1; i++)
            ans = ans + days[i];
        return ans;
    }
};
```
