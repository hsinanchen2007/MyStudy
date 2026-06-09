刚好之前做过一道题，一年中的第几天，leetcode 1154 直接搬过来。dayOfYear 函数就是
```
class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0,4));
        int mon[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if((year%4==0 && year%100!=0)||year%400==0)
            mon[1] = 29;
        int month = stoi(date.substr(5,2));
        int res = 0;
        for(int i=0;i<month-1;i++)
            res+=mon[i];
        int day = stoi(date.substr(8,2));
        res+=day;
        return res;
    }
    int daysBetweenDates(string date1, string date2) {
        if(date1>date2)
        {
            string tmp = date2;
            date2 = date1;
            date1 = tmp;
        }
        int day = 0;
        int y1 = stoi(date1.substr(0,4));
        int y2 = stoi(date2.substr(0,4));
        for(int i=y1+1;i<y2;i++)
        {
            if((i%4==0 && i%100!=0)||i%400==0)
                day+=366;
            else
                day+=365;
        }
        if(y1==y2)
        {
            int d1 = dayOfYear(date1);
            int d2 = dayOfYear(date2);
            return day+(d2-d1);
        }
        else
        {
            int d1 = dayOfYear(date1);
            if((y1%4==0 && y1%100!=0)||y1%400==0)
                d1 = 366 - d1;
            else
                d1 = 365 - d1;
            int d2 = dayOfYear(date2);
            return day+d2+d1;
        }
    }
};
```
