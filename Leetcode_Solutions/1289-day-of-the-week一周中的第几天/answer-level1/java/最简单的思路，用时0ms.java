```
class Solution {
    public String dayOfTheWeek(int day, int month, int year) {
        String week=null;
        int dayNum=0;
        dayNum=getYearNum(month, year)+getMonthNum(month, year)+day;
        switch (dayNum % 7) {
       case 3:
                week = "Saturday";
                break;
            case 4:
                week = "Sunday";
                break;
            case 5:
                week = "Monday";
                break;
            case 6:
                week = "Tuesday";
                break;
            case 0:
                week = "Wednesday";
                break;
            case 1:
                week = "Thursday";
                break;
            case 2:
                week = "Friday";
                break;
        }
        return week;
      
    }
      // 得出整年的天数
    public  int getYearNum(int month, int year) {
        
        int dayNum = 0;
        for (int i = year - 1; i >= 1970; i--) {
            if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
                dayNum += 366;
            else
                dayNum += 365;
        }
        return dayNum;
    }
    //得出整月的天数
     public  int getMonthNum(int month, int year){       
         int dayNum=0;
        for(int j=month-1;j>=1;j--){
            dayNum=dayNum+getDayNum(j, year);
        }
       return dayNum;
     }
    public  int getDayNum(int month, int year) {
        int dayNum=0;
        switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dayNum = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            dayNum = 30;
            break;
        case 2:
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
                dayNum = 29;
            else
                dayNum = 28;
            break;
        }
        return dayNum;
    }
}
```
