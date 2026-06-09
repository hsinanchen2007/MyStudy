### 解题思路
对于丑数序列 1, 2, 3, 4, 5, 6, 8, 9, 10, 12
我们发现其中的 每个数 乘以 2或者3或者5 可以得到下一个丑数
并且每个数乘以 2 3 5都只能乘以一次，例如 8=4*2 而不是2*2*2，第一个2*2已经得到4了，因此相当于是4*2，第一个2乘以2的次数已经用完了
因此我们用index_2 index_3 index_5表示某个数可以乘以2 3 5的位置，一旦乘以了2 3 5就index++
状态转移方程：dp[i] = Math.min(dp[index_2] * 2, dp[index_3] * 3);
             dp[i] = Math.min(dp[index_5] * 5, dp[i]);
更新下标：
        if(dp[i] == dp[index_2]*2){//例如： 4*2 = 8，说明4不能再乘以2了，因此index_2++;
            index_2++;
        }
        if(dp[i] == dp[index_3]*3){
            index_3++;
        }
        if(dp[i] == dp[index_5]*5){
            index_5++;
        }
### 代码

```java
class Solution {
    public int nthUglyNumber(int n) {
        if(n == 1){
            return 1;
        }

        int index_2 = 0;
        int index_3 = 0;
        int index_5 = 0;
        
        int[] dp = new int[n];
        dp[0] = 1;//dp[i]表示第i+1顺序的丑数
        for(int i = 1; i < n; i++){          
            dp[i] = Math.min(dp[index_2] * 2, dp[index_3] * 3);
            dp[i] = Math.min(dp[index_5] * 5, dp[i]);
            System.out.println(dp[i]);
            if(dp[i] == dp[index_2]*2){
                index_2++;
            }
            if(dp[i] == dp[index_3]*3){
                index_3++;
            }
            if(dp[i] == dp[index_5]*5){
                index_5++;
            }
        }
        return dp[n-1];
    }
}
```