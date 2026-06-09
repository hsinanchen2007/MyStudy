### 解题思路
最直接的思路是将数组排序，然后遍历求最大间距。但是python3内置的排序（Timsort）时间复杂度是O(nlog(n))，而且几乎所有语言的内置排序时间复杂度都是O(nlog(n))。本题要求线性时间复杂度和空间复杂度。

由于本题不需要真正将所有元素严格排序，只需要求出最大的间隔即可，考虑桶排序。将元素分配到不同的桶中，桶的大小一样，桶内的元素无序，且桶有序，有两种思路：
1. 对于n个元素的数组，有n+1个桶，那么至少会有一个空桶，那么最大间距一定是最大桶间间距（因为跨过空桶）。
2. n个元素的数组有n-1个间隔，所有元素间隔一致时的间隔是最小的最大间隔（因为缩小任意一个间隔，一定有另一个间隔增大），所以按平均分配间隔来建立桶，平均间隔为margin=max(1, (max-min)//(n-1))，桶的个数b=ceil((max-min)/margin)。由于桶的间隔被设置为最小的最大间隔，元素间的最大间隔一定出现在连续的桶间（桶内最大的间隔都不可能大于桶的大小）。桶间间隔由后面桶的最小值减去前面桶的最大值得到，跳过没有元素的桶。

时间复杂度：max()和min()都是O(n)，第一个循环是O(n)，第二个循环是O(b)，总的时间复杂度是O(n+b)。
空间复杂度：主要是存每个桶最大最小值的两个数组，O(b)
下面是按照第二种思路写的代码。

### 代码

```python3
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        if not nums or len(nums) < 2:
            return 0
        
        minima, maxima = min(nums), max(nums)
        if minima == maxima:
            return 0

        margin = max(1, (maxima - minima) // (len(nums) -1))
        bkt_size = (maxima - minima) // margin + 1
        
        bkt_min, bkt_max = [float("inf")] * bkt_size, [0] * bkt_size
        for num in nums:
            idx = (num - minima) // margin
            bkt_min[idx] = min(bkt_min[idx], num)
            bkt_max[idx] = max(bkt_max[idx], num)
        
        res = lastBktIdx = 0
        for i in range(1, bkt_size):
            if bkt_min[i] == float("inf") or bkt_max == 0:
                continue
            res = max(res, bkt_min[i] - bkt_max[lastBktIdx])
            lastBktIdx = i
        return res
        
```