### 解题思路
用date.split("-")取出String[] 再用Integer.parseInt()取得年月日，然后判断闰年用个boolean值，然后用一个int累计天数，先获得天数，月数减去1后，用for（）循环计算剩余月数，用switch（）计算1-11个可能，每次循环都判断一次有点费时，但我没想到内存消耗居然不大。

### 代码

```java
class Solution {
   public int dayOfYear(String date) {
        int num = 0;
        String[]dateArray= date.split("-");
        int year = Integer.parseInt(dateArray[0]);
        int month = Integer.parseInt(dateArray[1]);
        int day = Integer.parseInt(dateArray[2]);
        boolean runnian = false;
        if((year%4==0 && year%100 != 0) || year%400==0 ){
            runnian = true;
        }
        num += day;
        month--;
        for(int i= month;i>0;i--){
        switch (i){
            case 1:num += 31;
                   break;
            case 2:
                if(runnian) { 
                    num += 29;
                    break;
                }else {num += 28;
                    break;}
            case 3:num += 31;
                    break;
            case 4:num += 30;
                    break;
            case 5:num += 31;
                    break;
            case 6:num+=30;
                    break;
            case 7:num += 31;
                    break;
            case 8:num += 31;
                    break;
            case 9:num += 30;
                    break;
            case 10:num += 31;
                    break;
            case 11:num += 30;
                    break;
        }
        }
        return num;
    }
}
```