```
import java.time.LocalDate;
class Solution {
     public static String dayOfTheWeek(int day, int month, int year) {
    	String[] strings={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    	LocalDate date=LocalDate.of(year, month, day);
        int index=date.getDayOfWeek().getValue();
        index=index==7?0:index;
        return strings[index];
    }
}
```
