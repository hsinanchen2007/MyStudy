### 解题思路
先需要明确一个事情
  A[i] + A[j] + i - j）实际上是 (A[i] + i), (A[j]-j), 相当于a + b
  可以看做是从一个无序的列表中找到两个最大值,实际上题目的考点我个人理解也是这个意思.
  如果这样看题目的话,其实其购买股票的最大收益那道题思路是一样的,把地点当做一个状态
  观光组合是两个地方,所以次数k 为2, 当然使用股票的那个穷举状态解法是可以解决,k = 1, k=3
  咱们是解决一类问题,不是解决一个问题,这个解决范娜太牛皮了,如果你没看过,下面是地址
  https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/

  根据状态的解法是这样的
  for i in n 地点
      for j in k 组合的个数
  总共有n*k 这种组合,
  当 k = 2时
  dp[i][2] = max(dp[i-1][2], dp[i-1][1] + A[i] -i)
  // 第i个景点最多观光2次的最高分等于 前一个景点你的最多两次和前一个最多一次, 最多一次表明之前已经去过一个景点了,所以需要 减去 i
  dp[i][1] = max(dp[i-1][1], dp[i-1][0] + A[i] +i)
  // 第i个景点最多观光1次的最高分等于 前一个景点你的最多1次和前一个最多0次, 最多0次意思是不能去任何观光点了.
  base case
 dp[-1][-1] = -infinity
 //景点不存在的时候, 去了一个不存在的景点, 所以是不发生事件.
 dp[-1][k] = 0
 // 景点不存在的时候,最多有k次,是合理的,所以得分为 0
  单i = 0时需要考虑的问题
  dp[0][2] = max(dp[-1][2], dp[-1][1] + A[0] - 0)
           = max(0, A[0])
           = A[0]
 dp[0][1] = Math.max(dp[-1][1], dp[-1][0] + A[0] + 0) = A[0];

 dp[i][0] = Math.max(dp[-1][0], dp[-1][-1] + A[0] + 0)
          = dp[-1][0]
          = 0
具体代码实现如下
```
 int[][] dp = new int[A.length][3];
         for (int i = 0; i < A.length; i++){
             dp[i][0] = 0;
             if (i-1 == -1) {
                 dp[i][2] = A[0];
                 dp[i][1] = A[0];
                 continue;
             }
            dp[i][2] = Math.max(dp[i-1][2], dp[i-1][1] + A[i] - i);
            dp[i][1] = Math.max(dp[i-1][1],  A[i] + i);
         }
         return dp[A.length -1][2];
```
 通过观察发现, 只使用了中间状态所以,进行代码简化
```
   int dp_i1 = A[0];
         int dp_i2 = A[0];
         for (int i = 1; i < A.length; i++){
             dp_i2 = Math.max(dp_i2, dp_i1 + A[i] - i);
             dp_i1 = Math.max(dp_i1,  A[i] + i);
         }
         return dp_i2;
```
 当 k = 1时,就是取最大值
 当 k = 3时, 根据题目要求处理, k =1,2,3的时候的要求 

### 代码

```java
class Solution {
    public int maxScoreSightseeingPair(int[] A) {
        int dp_i1 = A[0];
        int dp_i2 = A[0];
        for (int i = 1; i < A.length; i++){
            dp_i2 = Math.max(dp_i2, dp_i1 + A[i] - i);
            dp_i1 = Math.max(dp_i1,  A[i] + i);
        }
        return dp_i2;
    }
}
```