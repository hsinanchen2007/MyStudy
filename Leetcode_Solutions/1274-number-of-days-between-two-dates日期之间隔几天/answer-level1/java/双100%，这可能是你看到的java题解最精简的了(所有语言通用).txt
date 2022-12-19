![image.png](https://pic.leetcode-cn.com/d818ecc00961e28b3f8ea2b5633adffc7e9d9b942f1a725c61a6d58d4cebdb88-image.png)
```java
class Solution {
    int[] _365M = new int[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public int daysBetweenDates(String date1, String date2) {
        int[] dates1 = parseDate(date1), dates2 = parseDate(date2);
        return Math.abs(calculateDays(dates1[0], dates1[1], dates1[2]) - calculateDays(dates2[0], dates2[1], dates2[2]));
    }

    int calculateDays(int year, int month, int day) {
        int dayC1 = day - 1;
        for (int i = month; i > 1; i--) dayC1 += _365M[i - 1 - 1];
        if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month > 2) dayC1++;
        dayC1 += (365 * (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400);
        return dayC1;
    }

    int[] parseDate(String date) {
        return new int[]{Integer.valueOf(date.substring(0, 4)), Integer.valueOf(date.substring(5, 7)), Integer.valueOf(date.substring(8, 10))};
    }
}
```

大概思路就是，2个日期都跟公元元年比，公元元年元日是公元1年1月1日，先把day归1，然后再把月归1，最后把年归1，比如2015年6月9日，9日相对1日，多出9-1=8天，
这样日期就是2015年6月9日了，然后再把月归一，分别减去前一个月的天数，从6月开始，6月1日到5月1日之间，差出整整5月份的天数，以此类推，归到1月1日后，
如果给定开始的日期大于等于3月1日，那么还需要在归1的时候，加上一个2月29日的一天（如果是闰年），最后把年归一，这里要看看闰年的定义，能被4整除，不能被100整除，
或者能被400整除的算闰年，于是先算算给定年份到公元1年，之间有多少个闰年，这里为什么需要year-1再除以4呢？比如给定日期是2012年x月x日，归1话日期以后，就是2012年，1月1日
当年的闰年，完全不算在内，所以要判断year-1以及以前的日期，有几个能被4整除的年份，然后再减去能被100整除的年份，其中，能被400整除的年份还要加回来，这样就ok了。
