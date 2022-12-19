### 解题思路
 按照动态规划的基本解题思路：
1.定义数组
2.初始化
3.找出状态转移方程
   

### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
        int dp[n+1] = {0};
        dp[0] = 1;//当n=0的时候，只有一种空树
        dp[1] = 1;//当n=1的时候，只有一个结点，只能构造一种二叉搜索树

        //动态规划，自底向上
        for(int i = 2; i <= n; i++)//让i来做根结点的情况
            for(int j = 1; j <= i; j++){
                dp[i] += dp[j - 1] * dp[i - j];
            }
        return dp[n];
    }
};

```