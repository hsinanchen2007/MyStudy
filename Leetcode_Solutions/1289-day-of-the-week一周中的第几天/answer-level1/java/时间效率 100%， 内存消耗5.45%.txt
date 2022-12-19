### 解题思路
![image.png](https://pic.leetcode-cn.com/ad63423fdb59ad252e905fd9253b0b3003ee84e6435fc3eb21702bb1c99df6ac-image.png)


从1971年1月1日（星期5）算起，
先算year年1月1日 是星期几
再算year年month月1日 是星期几
最后算year年month月day日 是星期几
其中需要构建 
星期数组 与 每月天数 数组 （都舍弃了第一个位置用来保证下标对应 星期数 与 月数）


### 代码

```java
class Solution {
    public String dayOfTheWeek(int day, int month, int year) {
        String[] weekDays = { "", "Monday", "Tuesday", 
                             "Wednesday", "Thursday", "Friday", "Saturday","Sunday"};
        int[] monthDays = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int  curDay = 5; //从1971-01-01开始算起
        //循环结束后将得到year年1月1号是星期几
        for(int y = 1971; y < year; ++y) {
            if(isLeapYear(y)) {
                curDay += 2;   
                curDay = getPreciseDay(curDay);
            }
            else {
                curDay += 1;
                curDay = getPreciseDay(curDay);
            }
        }
        //若year为闰年,则将二月改为29天
        if(isLeapYear(year)) {
            monthDays[2] = 29; 
        }
        int count = 0; //计算距离curDay有多少天
        //循环结束后将得到yean年month月1号是星期几
        for(int m = 1; m < month; ++m) {
            count += monthDays[m];
        }
        curDay += (count % 7);
        curDay = getPreciseDay(curDay);
        //下列语句执行后后将得到yean年month月day号是星期几
        count = day - 1;
        curDay += (count % 7);
        curDay = getPreciseDay(curDay);
    
        return weekDays[curDay];
    }
    //判断是否为闰年
    public boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
    //每次更新curDay以后，星期数可能会越界 需要进行处理  
    public int getPreciseDay(int day) {
        //如 curDay = 6, 计算后的curDay = 6 + 4 = 10 实际上curDay = 3
        //若计算后curDay大于7 ，则对7取模
        return day > 7 ? day % 7 : day;
    }
}
```