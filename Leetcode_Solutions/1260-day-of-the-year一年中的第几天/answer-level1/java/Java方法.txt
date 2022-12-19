### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int dayOfYear(String date) {
        if (date.length() != 10)
            return 0;
        int year = Integer.parseInt(date.substring(0,4));
        int month = Integer.parseInt(date.substring(5,7));
        int day = Integer.parseInt(date.substring(8,10));
        int[] days_of_month = {31,28,31,30,31,30,31,31,30,31,30,31};
        int result = day;
        switch (month) {
            case 1: return result;
            case 2: return result + days_of_month[0];
            default:break;
        }
        for (int i = 0; i < days_of_month.length; i++) {
            if (i == month - 1)
                break;
            result += days_of_month[i];
        }
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {    //365
            return result + 1;
        } else {//366
            return result;
        }
    }
}
```