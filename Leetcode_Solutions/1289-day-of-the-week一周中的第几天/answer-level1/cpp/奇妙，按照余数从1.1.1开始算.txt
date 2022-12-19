每年会多出来一天，相当于去年今天是周一，那今年今天是周二。当存在闰年，并且处于3月以及之后时，就会再往后多一天。按照year计算出现了多少个闰年，计算公式就是year/4 - year/100 + year/400。只有在今年3月以及之后，闰年多余的一天才会影响到当前的时间。
所以在计算闰年天数影响的时候，如果在1月或者2月，将year-1（但又不能忽略过了一年的影响，所以day++），否则就是year


```
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> dayTp{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        
        vector<int> ms{0,31,28,31,30,31,30,31,31,30,31,30,31};
        for(int i = 1; i < ms.size(); ++i)
        {
            ms[i] = (ms[i] + ms[i-1])%7;
            // printf("%d ", ms[i]);
        }
        // // printf("\n%d\n", 365%7);
        if(month < 3)
        {
            ++day;
            --year;
        }
        int di = (year/4 - year/100 + year/400 + year + ms[month - 1] + day - 1)%7;
        
        return dayTp[di];
    }
};
```
