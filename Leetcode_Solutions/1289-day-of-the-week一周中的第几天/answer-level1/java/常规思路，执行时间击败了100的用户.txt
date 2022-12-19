### 解题思路
1、设置一个num变量计算总天数
2、计算71年到现在经过的所有年份的天数，闰年366.平年365，加到num中
3、计算1月到现在每个月的总天数，加到num中
4、num中加上day
5、将num转化为星期即可

### 代码

```java
class Solution {
    public String dayOfTheWeek(int day, int month, int year) {
         int num=0;
		     int days[]=new int[]{31,28,31,30,31,30,31,31,30,31,30,31};
		     //计算年份
		     for(int i=1971;i<year;i++) {
		     if(i%4==0&&i%100!=0||i%400==0)
		    	 num+=366;
		     else
		    	 num+=365;
		     }
		     
		     if(year%4==0&&year%100!=0||year%400==0)
		    	 days[1]=29;  	 
		     for(int i=1;i<month;i++)
		     {
		    	 num+=days[i-1];
		     }
		     num+=day;
		     String[] ans_day=new String[]{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	         return ans_day[(num+4)%7];
    }
}
```