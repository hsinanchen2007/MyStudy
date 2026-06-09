### 解题思路
解题思路就是分别算出到1971.1.1的时间再求差
最开始是将字符串中的数字分离出来 
我直接使用的就是substring 简单易懂 还方便  当然这是因为这个字符串短小精悍
再者就是将string 转换为int
算出两个时间求差值
代码前面比较复杂 可能很很蠢  我不太会 如果有小伙伴 可以更加优化 欢迎告诉我
谢谢各位大佬了
### 代码

```java
class Solution { 
    public int daysBetweenDates(String date1, String date2) {
        int year1 = Integer.parseInt(date1.substring(0,4));
        int month1 = Integer.parseInt(date1.substring(5,7));
        int day1 = Integer.parseInt(date1.substring(8,10));
        int year2 = Integer.parseInt(date2.substring(0,4));
        int month2 = Integer.parseInt(date2.substring(5,7));
        int day2 = Integer.parseInt(date2.substring(8,10));
        return Math.abs(gapTo197111(year1,month1,day1) - gapTo197111(year2,month2,day2));
    }
    private int gapTo197111(int year , int month , int day){
        int[] days = new int[]{0,31,28,31,30,31,30,31,31,30,31,30,31};
        int sum = 0;
        for(int i = 1971 ; i < year ; i ++){
            sum += 365;
            if(isLeapyear(i)){
                sum ++;
            }
        }
        for(int i = 1 ; i < month ;i ++){
            sum += days[i];
        }
        if(isLeapyear(year) && month > 2){
                sum ++;
        }
        sum += day;
        return sum;
    }
    private boolean isLeapyear(int year){
        return (year % 400 == 0) || ((year % 4 ==0) && (year % 100 != 0));
    }
}
```