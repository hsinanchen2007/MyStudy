### 解题思路
知悉此题存在数学解法，但仍感觉不如动态规划稳扎稳打来得实在。
主要思路：在已知长度为n的绳子最大乘积的基础上，长度n+1绳子的最大乘积可能来源依赖于前面已知求解。
定义辅助数据结构：记长度为n的绳子最大乘积为s[n]，简单起见，不考虑索引偏移问题，初始化s = [1]*(n+1)。
假设当前处理长度为i的绳子最大乘积问题：
- 从i中截取一块长度为j的绳子，剩余长度i-j的最大乘积为s[i-j]，即最后一段长度为j的方案带来的乘积为j*s[i-j]；
- 对j从1到n-1进行遍历，取最大值；
- 由于我们假定长度i-j绳子最大乘积为s[i-j]的前提是要求i-j必须进行分割（m>1），然而对于从i中截取j这一事件本身已经满足分割要求，所以上述取最值还需增加一个补丁：即仅对长度i进行i-j和j两段分割的判断。

以上，即可得到稳扎稳打的动归解法。

### 结果
![image.png](https://pic.leetcode-cn.com/dc07da52082049e0c8499187ec7210561d34b118959e37498dbb70a058d6f4c9-image.png)

### 代码

```python3
class Solution:
    def cuttingRope(self, n: int) -> int:
        s = [1]*(n+1)
        for i in range(2, n+1):
            for j in range(1, i):
                s[i] = max(s[i], s[j]*(i-j), j*(i-j))
        return s[n]
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)
