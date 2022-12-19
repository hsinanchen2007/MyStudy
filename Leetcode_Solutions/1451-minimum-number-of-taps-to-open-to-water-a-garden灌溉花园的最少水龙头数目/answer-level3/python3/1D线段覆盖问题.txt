### 解题思路
可以转换为线段覆盖问题；直接将`ranges`转换为`intervals`，那么和线段拼接问题就很相似了

- 贪心算法：一个二阶的贪心算法 
    - O(Nlog(N))
    - [二阶贪心解法](https://leetcode-cn.com/problems/video-stitching/solution/greedy-xian-duan-pin-jie-lei-wen-ti-by-walkerlikes/)
- DP：
    - O(NT)
    - `d[i]` 表示浇灌到第i块土地需要至少多少水龙头；
    - 转移方程：`d[i] = min(d[i], d[i - current_left]+1` 表示考虑当前线段是否加入；

### 代码

```python
class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        # 1-D DP
        d = [n+1] * (n)
        # convert the ranges to intervals
        inters = []
        for ind, irange in enumerate(ranges):
            if irange:  # have watering intervals
                l, r = max(0, ind - irange), min(ind+irange-1, n-1)
                for j in range(l, r+1):
                    if l-1 < 0:
                        prev = 0
                    else:
                        prev = d[l-1]
                    d[j] = min(d[j], prev+1)
        return -1 if d[n-1] >= n+1 else d[n-1]
```