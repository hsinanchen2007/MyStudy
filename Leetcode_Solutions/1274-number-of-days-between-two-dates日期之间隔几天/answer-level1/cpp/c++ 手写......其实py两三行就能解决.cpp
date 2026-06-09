宏定义判断闰年，数组month记录每月的天数，求出两个年份与1970的天数差再相减取绝对值

```c++
#define year(x) (x%400 == 0 ||(x%4 == 0 && x%100 != 0))? 1 : 0
const int months[13][2] = {
    {0,0},
    {31,31},
    {28,29},
    {31,31},
    {30,30},
    {31,31},
    {30,30},
    {31,31},
    {31,31},
    {30,30},
    {31,31},
    {30,30},
    {31,31}
};
class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        int year1,month1,day1;
        int year2,month2,day2;
        int gap1 = 0, gap2 = 0;
        int n = date1.length();
        string tmp1 = "", tmp2 = "";
        for(int i = 0; i < 4; i++){
            tmp1 += date1[i];
            tmp2 += date2[i];
        }
        year1 = atoi(tmp1.c_str()); year2 = atoi(tmp2.c_str()); //atoi(tmp1.c_str())
        tmp1.clear();tmp2.clear();
        for(int i = 5; i < 7; i++){
            tmp1 += date1[i];
            tmp2 += date2[i];
        }
        month1 = atoi(tmp1.c_str()); month2 = atoi(tmp2.c_str());
        tmp1.clear();tmp2.clear();
        for(int i = 8; i < 10; i++){
            tmp1 += date1[i];
            tmp2 += date2[i];
        }
        day1 = atoi(tmp1.c_str()); day2 = atoi(tmp2.c_str());
        
        for(int i = 1971; i < year1; i++){
            if(year(i)) gap1 += 366;
            else gap1 += 365;
        }
        for(int i = 1971; i < year2; i++){
            if(year(i)) gap2 += 366;
            else gap2 += 365;
        }
        for(int i = 1; i < month1; i++){
            gap1 += months[i][year(year1)];
        }
        for(int i = 1; i < month2; i++){
            gap2 += months[i][year(year2)];
        }
        gap1 += day1 - 1;
        gap2 += day2 - 1;
        return (abs(gap1 - gap2));
    }
};
```