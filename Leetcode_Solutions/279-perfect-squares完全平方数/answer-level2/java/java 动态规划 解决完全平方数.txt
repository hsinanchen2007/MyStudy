### 解题思路
1、假设我们有一个dp[] 表示dp在坐标i的时候的和为n的最优解个数
2、同时我们有一个从1<i<Math.sqrt(n)+1的数组，
    int squarMax = Math.sqrt(n)+1;
    int[] squarNum = new int[squarMax];
    for(int i = 0;i<squarMax;i++){
        squarNum[i] = i*i;
    }
    因为squarNum[i]可以占据一项
    那么对于任意一个i,循环这个数组dp[i] = Math.min(dp[i],dp[i-squarNum[i]]+1)
    for(int i = 1;i<=n;i++){
        for(int j=1;j<squarMax;j++){
            if(i<squarNum[j]){
                break;
            }
            dp[i] = Math.min(dp[i],dp[i-squarNum[i]]+1);
        }
    }
    return dp[n];

### 代码

```java
class Solution {
    public int numSquares(int n) {
        //dp表示当坐标为i的时候的最优解个数
        int[] dp = new int[n+1];
        Arrays.fill(dp,Integer.MAX_VALUE);
        dp[0] = 0;
        int maxSquarNum = (int)Math.sqrt(n)+1;
        int[] squarNum = new int[maxSquarNum];
        for(int i = 1;i<maxSquarNum;i++){
            squarNum[i] = i*i;
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<maxSquarNum;j++){
                if(i<squarNum[j]){
                    break;
                }
                dp[i] = Math.min(dp[i],dp[i-squarNum[j]]+1);
            }
        }
        return dp[n];
    }
}
```