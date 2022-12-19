# 思路

思路很直接，计算和原点日期1972年1月1日的相隔天数，稍微有一点点麻烦就是闰年的处理

# 代码
```
class Solution {

    private int[] days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public int daysBetweenDates(String date1, String date2) {
        return Math.abs(parseDateToDay(date1) - parseDateToDay(date2));
    }

    private int parseDateToDay(String date){
        int year = Integer.parseInt(date.substring(0, 4));
        int month = Integer.parseInt(date.substring(5, 7));
        int day = Integer.parseInt(date.substring(8, 10));
        int res = 0;
        for(int i = 1971; i < year; i++){
            res += 365;
            if(isLeapYear(i)){
                res++;
            }
        }
        if(isLeapYear(year)){
            days[2] = 29;
        } else {
            days[2] = 28;
        }
        for(int i = 1; i < month; i++){
            res += days[i];
        }
        return res += day;
    }

    private boolean isLeapYear(int year){
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
}
```