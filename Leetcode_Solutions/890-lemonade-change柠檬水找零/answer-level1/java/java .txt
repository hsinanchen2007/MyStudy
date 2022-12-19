```
//题目中表达只有 三种货币 5,10,20 所以循环也就三种不需要考虑过多；
//在找零钱的过程中 如果有十元的先找十元的 如果没有十元的再找五元
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int five = 0 , ten = 0 ;
        for(int bill : bills){
            if(bill == 5){
                five++;
            }else if(bill == 10){
                ten++;
                five--;
                if(five < 0)
                    return false;
            }else{
                if(ten > 0){
                    ten--;
                    five--;
                    if(five < 0)
                        return false;
                }else if(five > 0){
                    five = five - 3;
                    if(five < 0) 
                        return false;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
}
```
