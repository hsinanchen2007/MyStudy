
**#闰年判断:**
```
((year % 4 == 0)&&(year % 100 != 0)) || (year % 400 == 0)
```
```
class Solution {
    static boolean isRun(int year){ 
        return year%100!=0&&year%4==0 || year%400==0;       //判断闰年
    }
    
    public static int daysBetweenDates(String date1, String date2) {       
        return Math.abs(getD(date1)-getD(date2));
    }
    static int[] m_days = new int[]{0,31,28,31,30,31,30,31,31,30,31,30,31};
    static int getD(String date1){
        String year = date1.substring(0,4);
        int year1 = Integer.parseInt(year);
        String moth = date1.substring(5,7);
        int moth1 = Integer.parseInt(moth);
        String date = date1.substring(8,10);
        int date11 = Integer.parseInt(date);
        int sum=0;
        for(int i=1971; i<year1; i++){
            if(isRun(i)){
                sum += 366;
            }else{
                sum += 365;
            }
        }
        for(int i=1; i<moth1; i++){
            if(i==2 && isRun(year1)){
                sum += 29;
            }else if(i==2 && !isRun(year1)){
                sum += 28;
            }else{
                sum += m_days[i];
            }
        }
        return sum+date11;
    }
}
```
