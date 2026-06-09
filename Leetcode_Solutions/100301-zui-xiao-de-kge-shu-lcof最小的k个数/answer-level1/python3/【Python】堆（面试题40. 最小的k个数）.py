## 思路

数据没有规律。那么不多说，直接考虑堆。建立一个大小为k的大顶堆，由于是大顶堆，因此堆顶的那个数一定是堆中最大的数。遍历过程中，如果当前数比堆顶的数小，那么将堆顶的数换成这个更小的数，并重新堆化（heapify）。这样下去之后，我们的堆的容量会维持k不变，并且堆中的元素一定是最小的k个元素。

## 代码

```python
class Solution:
    def getLeastNumbers(self, nums: List[int], k: int) -> List[int]:
        if k == 0: return []

        n, opposite = len(nums), [-1 * x for x in nums[:k]]
        heapq.heapify(opposite)
        for i in range(k, len(nums)):
            if -opposite[0] > nums[i]:
                # 维持堆大小不变
                heapq.heappop(opposite)
                heapq.heappush(opposite, -nums[i])
        return [-x for x in opposite]
```

也可以一行代码：

```python
class Solution:
    def getLeastNumbers(self, nums: List[int], k: int) -> List[int]:
        return heapq.nsmallest(k, nums)
```

**复杂度分析**
- 时间复杂度：$O(nlogk)$
- 空间复杂度：$O(k)$

更多题解可以访问我的LeetCode题解仓库：https://github.com/azl397985856/leetcode  。 目前已经接近30K star啦。

大家也可以关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)