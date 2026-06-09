执行用时 :2 ms, 在所有 Java 提交中击败了98.66%的用户  
内存消耗 :34.5 MB, 在所有 Java 提交中击败了100.00%的用户  
```
class Solution {
    public int dayOfYear(String date) {
        int[] dayOfMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = getNum(date, 0, 4);
        int month = getNum(date, 5, 7);
        int day = getNum(date, 8, 10);
        if(isLeapYear(year)) dayOfMonth[1]=29;
        int sum = 0;
        for(int i=0;i<month-1;i++) {
            sum += dayOfMonth[i];
        }
        sum += day;
        return sum;
    }
    
    private boolean isLeapYear(int n) {
        if(n%4==0 && n%100!=0 || n%400==0) {
            return true;
        }
        else {
            return false;
        }
    }
    
    private int getNum(String date, int begin, int end) {
        int sum = 0;
        for(int i=begin;i<end;i++) {
            sum = sum*10 + (date.charAt(i)-'0');
        }
        return sum;
    }
}
```