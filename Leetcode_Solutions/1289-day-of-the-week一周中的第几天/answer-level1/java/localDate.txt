### 解题思路
### 变量需要初始化时，先将其设置为null。
`localDate`对象获取方式：1.now();2.of

### 代码

```java
import java.time.LocalDate;
class Solution {
    public String dayOfTheWeek(int day, int month, int year) {
        LocalDate LocalDate=null;
        LocalDate=LocalDate.of(year,month,day);
        String[] weeks={ "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"};
        int weekDay= LocalDate.getDayOfWeek().getValue();
        return weeks[weekDay-1];

    }
}
```