选取起点为0或1就可以求出奇偶数组的情况了。

![image.png](https://pic.leetcode-cn.com/94b89dc03aab381c01228150e93a7ae65869f79d277d200af2df6424d420d1a7-image.png)


```py
class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        n, ans = len(nums), [0, 0]
        for k in [0, 1]:
            for i in range(k, n, 2):
                d = 0
                if i > 0:
                    d = max(d, nums[i] - nums[i - 1] + 1)
                if i + 1 < n:
                    d = max(d, nums[i] - nums[i + 1] + 1)
                ans[k] += d
        return min(ans)
```
