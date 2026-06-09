最普通算法求解
![image.png](https://pic.leetcode-cn.com/3beb96792644f07b0bfa8c74d43654b67a084aaf9b8d424045188dc1a826b96f-image.png)



class Solution {

    public int dayOfYear(String date) {
        int year = Integer.parseInt(date.substring(0,4));
        int mon = Integer.parseInt(date.substring(5,7));
        int day = Integer.parseInt(date.substring(8,10));
        int sumday = 0;
        for(int i = 1; i < mon ;i++){ 
            if(i == 4||i == 6 || i == 9 || i == 11){
                sumday += 30;
            }else if(i == 2){
                if((year%4==0&&year%100!=0)||year%400==0){
                    sumday += 29;
                }else{
                    sumday += 28;
                }
            }else{
                sumday += 31;
            }
        }
        sumday += day;
        return sumday;
    }

}