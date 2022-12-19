执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
内存消耗 :8.2 MB, 在所有 cpp 提交中击败了100.00%的用户

有两个要注意的地方是，当年的1，2月要当作上一年的13，14月来计算；w如果是负数的情况取模要注意。

```
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        
        //泰勒公式
        int w = 0;//星期
        int m = month;//月份
        int y = year%100;//年 年份后两位数
        int c = year/100;//世纪 年份除以100
        
        
        //注意！1,2月要当成上一年的13,14月计算
        if(month == 1||month == 2){
            
            y = (int)(year - 1)%100;
            c = (int)(year - 1)/100;
            m = m + 12;
        }
        
        
        w = y + (int)y/4 + (int)c/4 - (int)2*c + (int)(26*(m + 1)/10) + day -1;//要计算的日期是在1582年10月4日之后的情况
        w = (w%7 + 7)%7;//w对7取模得星期数
   
        
        string ans;
        
        switch(w)
        {
            case 0:
                ans = "Sunday";
                break;
            case 1:
                ans = "Monday";
                break;
            case 2:
                ans = "Tuesday";
                break;
            case 3:
                ans = "Wednesday";
                break;
            case 4:
                ans = "Thursday";
                break;
            case 5:
                ans = "Friday";
                break;
            case 6:
                ans = "Saturday";
                break;
        }
        
        return ans;
    }
};
```

