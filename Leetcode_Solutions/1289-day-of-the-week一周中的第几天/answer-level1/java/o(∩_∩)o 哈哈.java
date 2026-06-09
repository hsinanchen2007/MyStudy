### 解题思路
根据题意找到三个数组，又根据1971年1月一日是星期五，四年一轮回判断出有多少闰年，
从日开始累加，共多少天，要注意输入的年份的计算

### 代码

```java
class Solution {
    String[] xingqi={"Thursday","Friday", "Saturday","Sunday","Monday", "Tuesday", "Wednesday", "",};
    int[] rm={31,29,31,30,31,30,31,31,30,31,30,31};
    int[] lm={31,28,31,30,31,30,31,31,30,31,30,31};

    public String dayOfTheWeek(int day, int month, int year) {//1971,1,1xingqiwu
       int num=day;
       for(int i=0;i<month-1;i++){
           if(year%4==0)
            num=num+rm[i];
           else 
            num=num+lm[i];
       }
       int y=year-1971;
       int runYear=(y%4==0)?y/4:((y%4>=2)?(y/4+1):y/4);//判断多少闰年
       
       if(year%4==0)
        num=num+(y-runYear)*365+(runYear)*366;
       else
         num=num+(y-runYear)*365+(runYear)*366;
        return xingqi[num%7];
        
    }
}
```