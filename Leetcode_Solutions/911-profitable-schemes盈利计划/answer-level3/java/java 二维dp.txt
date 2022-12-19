### 解题思路
思路同背包问题，使用二维数组保存之前状态，第一维是利润，第二维是人数

需要注意的问题是当：利润大于P时就使用 P 来表示 >=P的利润

### 代码

```java
class Solution {
    public int profitableSchemes(int G, int P, int[] group, int[] profit) {
        int[][] dp = new int[P+1][G+1];
        int mod = (int)1e9 + 7;
        dp[0][0] = 1;
        int N = group.length;
        
        for(int i=0 ; i<N ; i++){
            int g = group[i];
            int p = profit[i];
            for(int j=P ; j>=0 ; j--){
                for(int k=G-g ; k>=0 ; k--){
                    //利润>=P时，使用P来代替
                    int x = j+p>=P ? P : j+p;
                    dp[x][k+g] = ( dp[x][k+g] + dp[j][k])%mod;
                }
            }
        }
        long res = 0;
        
        for(int i=0 ; i<=G ; i++){
            res = (res + dp[P][i])%mod;
        }
        return (int)(res%mod);
    }
}
```