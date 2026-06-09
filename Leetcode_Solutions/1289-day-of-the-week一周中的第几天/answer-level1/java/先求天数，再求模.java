### 解题思路
把所有的从1971年1月1日的天数加起来，由于1971年1月1日是周五，就可以通过取余算出答案。
![image.png](https://pic.leetcode-cn.com/7d0f3a2ba93d1dae2b387dac1bec9c33a4a5e25e8f75a4bf831cc980eb831842-image.png)

### 代码

```java
class Solution {
    public String dayOfTheWeek(int day, int month, int year) {
        String[] weekdays = new String[]{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int[] daysOfMonth = new int[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // 处理日
        int daySum = day;
        // 处理月
        for (int i = 0; i < month - 1; i++) {
            daySum += daysOfMonth[i];
        }
        if (isLeapYear(year) && month > 2) {
            daySum += 1;
        }
        // 处理年
        int yearCnt = year - 1971;
        int leapYearCnt = (year - 1) / 4 - 1971 / 4 - ((year - 1) / 100 - 1971 / 100) + ((year - 1) / 400 - 1971 / 400);

        daySum = daySum + yearCnt * 365 + leapYearCnt;

        // 1971/1/1是周五
        int idx = (daySum + 4) % 7;
        return weekdays[idx];
    }

    private boolean isLeapYear(int year) {
        return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
    }
}
```