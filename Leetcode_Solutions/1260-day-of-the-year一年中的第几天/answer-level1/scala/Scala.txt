### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def dayOfYear(date: String): Int = {
    import java.util.GregorianCalendar
    val arr = date.split("-")
    val year = Integer.valueOf(arr(0))
    val month = Integer.valueOf(arr(1))
    val day = Integer.valueOf(arr(2))
    val cal = new GregorianCalendar(year, month - 1, day)
    cal.get(java.util.Calendar.DAY_OF_YEAR)    
    }
}
```