### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int n = A.length;
        if(n < 3){
            return 0;
        }
        // 记录以n为下标的前三个元素是否等差
        boolean[] dengCha = new boolean[n];
        for(int i = 2; i < n; i++){
            if(A[i] - A[i-1] == A[i-1] - A[i-2]){
                dengCha[i] = true;
            }
        }

        // n为结束时，一共有多少等差数组
        int[] dp = new int[n];
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i < n; i++){
            if(dengCha[i]){
                // 已经确认最后三个是等差，再往前找
                int cnt = 1;
                for(int j = i-1; j >= 0; j--){
                    if(!dengCha[j]){
                        break;
                    }
                    else{
                        cnt++;
                    }
                }
                dp[i] = dp[i-1] + cnt;
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
}
```