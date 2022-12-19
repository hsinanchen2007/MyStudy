### 解题思路
先对每一对(height, weight)进行排序（先按照height递增排序，height相同则按照weight递增排序），该问题就转化为了：寻找weight的最长严格递增子序列，同时要满足这一子序列对应的height也是严格递增的。

如果没有“对应的height也要严格递增”这一要求，那这个问题就相当于[https://leetcode-cn.com/problems/longest-increasing-subsequence/](300. 最长上升子序列)，其思路是：
    1. 维护一个数组dp，dp[i]的意义是：**长度为(i+1)的weight严格上升子序列中，末尾的weight最小是多少**。
    2. 对于每一个weight，如果dp[-1]小于weight，则把weight添加到dp末尾；否则寻找dp中第一个大于等于这一weight的项，将这一项更新为weight。（为了节省时间，这一步可用二分查找来做，或使用库函数bisect.bisect_left）
    3. 遍历完每一个weight后，答案即是dp的长度。
    
现在，添加了必须满足“对应的height也要严格递增”的要求，那么上述对dp的更新必须做一定**延迟**。
假设我们先处理(50, 60)，将其填入了dp[i]，再处理(50, 70)时，有可能会正好填入dp[i+1]，这就不合法了，因为dp[i]的height并没有严格小于dp[i+1]。
那么，我们需要先记录(50, 60)填入的位置（但不填入），再记录（50, 70）填入的位置……等到下一个height严格大于50（或者到达尽头）时，再将所有height为50的一一填入。

### 代码

```python3
class Solution:
    def bestSeqAtIndex(self, height: List[int], weight: List[int]) -> int:
        hw = sorted(zip(height, weight))
        
        dp = [] # dp[i]: 长度为(i+1)的(height, weight)双严格上升子序列中，末尾的weight最小是多少
        temp = []
        for i in range(len(hw)):
            # temp: 记录(要填入的体重, 要填入的位置)
            temp.append((hw[i][1], bisect.bisect_left(dp, hw[i][1])))

            # 到达尽头或下一个height严格变大时，开始填入
            if i == len(hw) - 1 or hw[i][0] < hw[i+1][0]:
                for w, i in temp:
                    # 添加到dp末尾
                    if i == len(dp):
                        dp.append(w)
                    # 更新dp[i]；注意同一height下weight是递增的，所以不能直接赋值，要取较小者
                    else:
                        dp[i] = min(dp[i], w)
                temp = []
        return len(dp)
```