```
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int[] money=new int[2];
        money[0]=0;
        money[1]=0;
        for(int i=0;i<bills.length;i++){
            if(bills[i]==5){
                money[0]++;
            }
            if(bills[i]==10){
                if(money[0]==0){
                    return false;
                }else{
                    money[0]--;
                    money[1]++;
                }
            }
            if(bills[i]==20){
                if(money[0]>0 && money[1]>0){
                    money[0]--;
                    money[1]--;
                }else if(money[0]>=3){
                    money[0]-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
}
```
