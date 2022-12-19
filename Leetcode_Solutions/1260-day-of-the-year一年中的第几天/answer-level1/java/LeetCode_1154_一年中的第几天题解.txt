### 解题思路

要点：当年份为闰年且月份大于2月的时候，天数才 + 1，否则直接返回结果

### 代码

```java
class Solution {
    private final static int[] daysOfMouth = new int[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public int dayOfYear(String date) {
        String[] times = date.split("-");
        int days = Integer.parseInt(times[2]);
        int tmp = days;
        if ("01".equals(times[1])) return days;
        int mouth = Integer.parseInt(times[1]) - 1;
        for (int i = 0; i < mouth; i++) {
            days += daysOfMouth[i];
        }
        int year = Integer.parseInt(times[0]);
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && (mouth > 1) ? days + 1 : days;
    }
}
```