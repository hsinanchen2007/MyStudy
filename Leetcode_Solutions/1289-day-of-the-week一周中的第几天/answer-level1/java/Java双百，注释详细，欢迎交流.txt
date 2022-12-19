```
class Solution {
    int[] mDay = new int[] {0,31,28,31,30,31,30,31,31,30,31,30,31};
    String[] wDay = new String[] {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    public String dayOfTheWeek(int day, int month, int year) {
        int dayGap = dayGap(day, month, year);
        return wDay[(dayGap+5) % 7];
    }

    //计算距1970年1月1日多少天（1970年1月1日是周五）
    private int dayGap(int day, int month, int year) {
        int dayGap = 0;

        //加上每年的天数
        for(int i = 1971; i < year; i++) {
            dayGap += isLeapYear(i) ? 366 : 365;
        }

        //加上每月的天数
        for(int i = 1; i < month; i++) {
            dayGap += mDay[i];
        }

        //如果当年是闰年且月份大于2，要补上2月少算的那一天
        dayGap += isLeapYear(year) && month > 2 ? day + 1 : day;
        
        //减去1971.1.1当天
        dayGap--; 

        return dayGap;
    }

    //判断是否为闰年
    private boolean isLeapYear(int year) {
        return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    }
}
```
