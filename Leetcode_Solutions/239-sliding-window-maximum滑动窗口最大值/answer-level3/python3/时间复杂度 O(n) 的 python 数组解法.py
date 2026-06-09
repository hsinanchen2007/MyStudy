时间复杂度为 `O(n)`：每个元素被处理2次，添加到索引数组 `indexs`  中和从索引数组中删除。

```python
class Solution:
    def maxSlidingWindow(self, nums, k: int):
        if nums is None or len(nums) == 0:
            return []
        if k == 1:
            return nums
        # 存储窗口内最大值的索引
        indexs = []
        res = []
        for i in range(len(nums)):
            # 值个数超了 滑出第一个值
            if indexs and i - indexs[0] >= k:
                indexs.pop(0)
            # 新加入的值比前面的值大，则覆盖前面的值
            while indexs and nums[i] > nums[indexs[-1]]:
                indexs.pop()
            # 添加新的值
            indexs.append(i)
            if i >= k-1:
                res.append(nums[indexs[0]])
        return res
```