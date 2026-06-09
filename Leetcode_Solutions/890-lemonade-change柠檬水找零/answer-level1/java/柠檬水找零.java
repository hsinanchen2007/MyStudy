# 贪心法
实质只有一个：当20元出现时，优先找10元

```java []
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int[] dp=new int[2];
        for(int b:bills){
            if(b==5) dp[0]+=1;
            else if(b==10){
                if(dp[0]==0) return false;
                dp[0]-=1;dp[1]+=1;
            }
            else{
                if(dp[1]>0) {dp[1]-=1;dp[0]-=1;}
                else dp[0]-=3;
                if(dp[0]<0) return false;
            }
        }
        return true;
    }
}
```
