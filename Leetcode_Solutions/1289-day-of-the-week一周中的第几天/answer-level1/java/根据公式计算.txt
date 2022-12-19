给定年月日计算星期几的公式有多种，此处列举一个计算方便的公式。
W = x + [x / 4] + [c / 4] - 2c + [26(m + 1) / 10] + d - 1
其中，c表示年份前两位，x表示年份后两位，m表示月，1月和2月看成上一年的13月和14月，d表示日。方括号表示向下取整。对W计算除以7的余数即可知道是星期几，余数是0表示星期日，余数是1到6分别表示星期一到星期六。需要注意的是W可能是负值，因此计算除以7的余数之后需要判断是大于等于0还是小于0，如果小于0则将余数加7。
```
class Solution {
    public String dayOfTheWeek(int day, int month, int year) {
        final String[] DAYS = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int dayIndex = getDayIndex(day, month, year);
        return DAYS[dayIndex];
    }

    public int getDayIndex(int day, int month, int year) {
        if (month < 3) {
            month += 12;
            year--;
        }
        int century = year / 100, year2 = year % 100;
        int index = year2 + year2 / 4 + century / 4 - 2 * century + 26 * (month + 1) / 10 + day - 1;
        index %= 7;
        if (index < 0)
            index += 7;
        return index;
    }
}
```

