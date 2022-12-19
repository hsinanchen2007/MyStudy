### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int superEggDrop(int K, int N) {
        //dp[k][m] 的含义是k个鸡蛋 移动m次最多能够确定多少楼层
        //第一个鸡蛋扔完，碎了剩下能确定的dp[k - 1][m - 1]下边的楼层，没碎剩下能确定的dp[k][m - 1]上        边的楼层，+1本层
        //dp[k][m] = dp[k - 1][m - 1] + dp[k][m - 1] + 1
        //dp[k][1]=1;dp[1][m]=m

        // 可直接给出解
       if (K == 1 || N == 1 || N == 2) 
         {
            return N;
         }
//由于 m 为所求值，创建二维数组时，无法确定 m 值，因此，以 一维数组 代替 二维数组 进行计算；则每一个坐标的值等于 当前位置值 + 前一位置值 + 1

          // 初始化首列（第一步）
        int *dp = new int[K + 1];
          for (int index = 1; index <= K; index++) 
          {
         dp[index] = 1;
         }

         // 从第二步开始计算
        int m = 2;
    while (true) 
    {
          for (int k = K; k > 1; k--) 
        {  // 从后向前计算，以免 k-1 位置过早被新值覆盖，导致后续计算错误。
        //相当于还带有m-1，dp[k][m] = dp[k - 1][m - 1] + dp[k][m - 1] + 1，形式上省略了
        dp[k] = dp[k] + dp[k - 1] + 1;
        }

      // 判断是否满足条件
      if (dp[K] >= N) 
      {
        return m;
      } 
      else 
      {
        dp[1] = m;  // 覆盖首位值
        m++;  // 进入下一步
      }
          
    }

    }
};
```