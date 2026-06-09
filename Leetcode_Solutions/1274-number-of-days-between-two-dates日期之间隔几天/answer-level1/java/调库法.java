```
import java.text.SimpleDateFormat;
import java.util.Date;
class Solution {
    public int daysBetweenDates(String date1, String date2) {
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
        try {
            long diff = Math.abs(sdf.parse(date1).getTime() - sdf.parse(date2).getTime());
            return (int)(diff / (1000 * 60 * 60 * 24));
        } catch (Exception e) {
            System.out.println("Worng inputs!");
            return 0;
        }
    }
}
```
