```
class Solution {
   public  int dayOfYear(String date) {
         int[] monthNum={31,28,31,30,31,30,31,31,30,31,30,31};
        int year = Integer.parseInt(date.substring(0, 4));
        int month = Integer.parseInt(date.substring(5, 7));
        int day = Integer.parseInt(date.substring(8, 10));
        int dayNum=0;
        if ((year % 4 == 0 && year % 100 != 0 )|| year % 400 == 0)
                 monthNum[1]= monthNum[1]+1;
        for(int i=0;i<month-1;i++){   
            dayNum+=monthNum[i];
        }
        dayNum+=day;
        return dayNum;
    }
}
```
