### 解题思路
耗时超过100%的用户，内存消耗超过100%用户
### 代码

```cpp
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        string res[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

        int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int month_run[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
        // 2019-243 = 7
        int days = 0;
        
        if(year%4==0)
        {
            for(int i=0;i<(month-1);i++)
            {
                days = days + month_run[i];
            }
            days = days + day;
        }
        else
        {
            for(int i=0;i<(month-1);i++)
            {
                days = days + months[i];
            }
            days = days + day;
        }

        
        while(year!=2019)
        {

            if(year>2019&&(year-1)%4==0)
            days = days + 366;
            else if(year>2019&&(year-1)%4!=0)
            days = days + 365;
            else if(year<2019&&(year)%4==0)
            days = days - 366;
            else
            days = days - 365;

            if(year<2019)
            year++;
            else if(year>2019)
            year--;
            else
            break;

        }

        days = days - 243;
        days = days%7;
        if(days < 0)
        days = days + 7;

        if (days==0)
        return res[6];
        else 
        return res[days-1];
    }
};
```