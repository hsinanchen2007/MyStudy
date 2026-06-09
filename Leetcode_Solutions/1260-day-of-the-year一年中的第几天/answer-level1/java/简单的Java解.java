``` java
class Solution {
    int[] dayOfMonth = new int[] {
            0,
            31, // Jan
            28, // Feb
            31, // Mar
            30, // Apr
            31, // May
            30, // Jun
            31, // Jul
            31, // Aug
            30, // Sep
            31, // Oct
            30, // Nov
            31 // Dec
    };
    public int ordinalOfDate(String date) {
        String[] dateParts = date.split("-");
        int year = Integer.parseInt(dateParts[0]);
        int month = Integer.parseInt(dateParts[1]);
        int dayInMonth = Integer.parseInt(dateParts[2]);
        int days = 0;
        for (int i = 1; i < month; ++i) {
            days += dayOfMonth[i];
        }
        days += dayInMonth;
        if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) days += 1;
        return days;
    }
}
```