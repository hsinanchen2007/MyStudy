### 前言
![图片.png](https://pic.leetcode-cn.com/7bf05e42bb31e224d06701cf72a96cfa4ac0c4cd5fdc927ec0b6fa5198449b66-%E5%9B%BE%E7%89%87.png)

如果你刚刚听说动态规划，还不太明白 `dp` 为啥要定义成这样，转移方程是啥。  
欢迎来看一下这篇题解，看完能稍微理解一下动态规划到底做了什么事？  
或许芭。

### 思路
1. 动态规划

2. 定义 `dp[i][j]`
    21. `dp[i][j]` 代表 `word1` 中前 `i` 个字符，变换到 `word2` 中前 `j` 个字符，最短需要操作的次数
    22. 需要考虑 `word1` 或 `word2` 一个字母都没有，即全增加/删除的情况，所以预留 `dp[0][j]` 和 `dp[i][0]`

3. 状态转移
    31. **增**，`dp[i][j] = dp[i][j - 1] + 1`
    32. **删**，`dp[i][j] = dp[i - 1][j] + 1`
    33. **改**，`dp[i][j] = dp[i - 1][j - 1] + 1`
    34. 按顺序计算，当计算 `dp[i][j]` 时，`dp[i - 1][j]` ， `dp[i][j - 1]` ， `dp[i - 1][j - 1]` 均已经确定了
    35. 配合增删改这三种操作，需要对应的 `dp` 把操作次数加一，取三种的最小
    36. 如果刚好这两个字母相同 `word1[i - 1] = word2[j - 1]` ，那么可以直接参考 `dp[i - 1][j - 1]` ，操作不用加一

### 图解
绿色：增  
红色：删  
黄色：改  

<![图片.png](https://pic.leetcode-cn.com/62ea5e33d1ee2396c74c87941269bc1e53cd7385c341c49b160129f2e49de80e-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/d892c5f4463bc801dff85fed4c8b8e76ed0d178b1b917a4447b642c243d46c51-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/36684da0c9884d45a3aa96e20dd99caf58e83d3ab0e0892195908137c2f9f57d-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/ac37cf1f89871907b9b435a00333bea9d2826d3f739e09a1f5a212d1b1210d19-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/1639bd7e5f7a85a80af26717b18040b8613050df79637d2ef51cdf5d7da9e8c1-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/0dcfe026d511c5e66e64369311b75f5d5d3660b19261762a13c337e90de815a4-%E5%9B%BE%E7%89%87.png)>

### 答题
```C++ []
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        for (int i = 0; i < dp.size(); i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j < dp[0].size(); j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 1; j < dp[i].size(); j++)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }
        return dp.back().back();
    }
};
```

### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

**如果感觉还不错就点个赞吧~**

这是 [我的leetcode](https://github.com/AhJo53589/leetcode-cn) ，帮助我收集整理题目，可以方便的 `visual studio` 调试，欢迎关注，star

