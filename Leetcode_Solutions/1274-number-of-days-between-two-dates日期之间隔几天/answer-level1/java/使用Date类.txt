创建 Date 类时，需要将年份减去 1900 ，月份减去 1。
由于 getTime() 方法得到的时间是以毫秒为单位的，所以换算成天数需要除以 86400000。
1000 * 3600 * 24 = 86400000
（1 s = 1000 ms, 1 h = 3600 s, 1 day = 24 h）

```
import java.util.*;

class Solution {
    public int daysBetweenDates(String date1, String date2) {
        String[] d1 = date1.split("-");
        String[] d2 = date2.split("-");
	Date a = new Date(Integer.parseInt(d1[0]) - 1900,Integer.parseInt(d1[1]) - 1,Integer.parseInt(d1[2]));
	Date b = new Date(Integer.parseInt(d2[0]) - 1900,Integer.parseInt(d2[1]) - 1,Integer.parseInt(d2[2]));
	return (int)Math.abs((a.getTime() - b.getTime()) / 86400000);
    }
}
```
