1、获取Calendar 对象calendar。
2、设置calendar。注意：月份需减一。
3、通过Calendar.DAY_OF_WEEK 得到一周的第几天。注意：1->Sunday,2->Monday,...

代码如下：
```
import java.util.Calendar;
public String dayOfTheWeek(int day, int month, int year) {
    Calendar calendar = Calendar.getInstance();
    calendar.set(year, month-1, day);
    int dayOfWeek = calendar.get(Calendar.DAY_OF_WEEK);
    if (1 == dayOfWeek) {
        return "Sunday";
    } else if (2 == dayOfWeek) {
        return "Monday";
    } else if (3 == dayOfWeek) {
        return "Tuesday";
    } else if (4 == dayOfWeek) {
        return "Wednesday";
    } else if (5 == dayOfWeek) {
        return "Thursday";
    } else if (6 == dayOfWeek) {
        return "Friday";
    } else if (7 == dayOfWeek) {
        return "Saturday";
    } else {
        return null;
    }
}
```
