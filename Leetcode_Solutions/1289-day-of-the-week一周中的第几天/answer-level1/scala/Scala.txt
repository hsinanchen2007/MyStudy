### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    import java.util.Calendar
    def dayOfTheWeek(day: Int, month: Int, year: Int): String = {
     val arr = Array[String]("Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday")
    val calendar = Calendar.getInstance();
    calendar.set(Calendar.YEAR, year);
    calendar.set(Calendar.MONTH, month - 1);
    calendar.set(Calendar.DAY_OF_MONTH, day);
    arr(calendar.get(Calendar.DAY_OF_WEEK) - 1)   
    }
}
```