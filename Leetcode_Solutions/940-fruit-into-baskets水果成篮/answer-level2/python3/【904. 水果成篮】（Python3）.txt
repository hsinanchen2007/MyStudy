## 思路

问题可以抽象为`给定一个数组，求解最多选择两种数字的情况下，最大的连续子序列长度`，其中数组和原题目一样，每一个数字代表一个水果。

我们可以使用滑动窗口来解决。 思路和 [【1004. 最大连续 1 的个数 III】滑动窗口（Python3）](https://leetcode-cn.com/problems/max-consecutive-ones-iii/solution/1004-zui-da-lian-xu-1de-ge-shu-iii-hua-dong-chuang/) 一样。

## 代码


```python
class Solution:
    def atMostK(self, nums, K):
        counter = collections.Counter()
        res = i = 0
        for j in range(len(nums)):
            if counter[nums[j]] == 0:
                K -= 1
            counter[nums[j]] += 1
            while K < 0:
                counter[nums[i]] -= 1
                if counter[nums[i]] == 0:
                    K += 1
                i += 1
            res = max(res, j - i + 1)
        return res

    def totalFruit(self, tree: List[int]) -> int:
        return self.atMostK(tree, 2)
```

**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(N))$ （我们使用了Counter）

更多题解可以访问我的LeetCode题解仓库：https://github.com/azl397985856/leetcode  。 目前已经接近30K star啦。

大家也可以关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/3ecb77aceaf5545ad8bc8609fe99dd7163dfd28d006f7fd7d885a6b6e971f9ed)
