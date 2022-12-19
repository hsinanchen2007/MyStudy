个位数有0这个特殊情况。可以继续往后加数字的只有9个
两位数根据个位数增加数字，有9*10种情况，减去9种与第一个数字重复的情况，得到81个。（那么81+10=91）
**以此类推dp[i]=dp[i-1]\*(11-i);**
另：n大于10无意义，因为十个数字都用了

```
class Solution {
    public int countNumbersWithUniqueDigits(int n) {

        if(n==0)
            return 1;
      if(n>10){
          n=10;
      }//大于10没有意义了,因为十个数字都用了.
      if(n==1){
          return 10;
      }
        if(n==2){
            return 91;
        }
      int dp[]=new int [11];
      dp[1]=10;
      dp[2]=81;
      for(int i=3;i<=n;i++){
          dp[i]=dp[i-1]*(11-i);
      }
        
        
    int  sum=0;
    for(int i=1;i<=n;i++){
        sum+=dp[i];
    }
        return sum;
    }
}
```
