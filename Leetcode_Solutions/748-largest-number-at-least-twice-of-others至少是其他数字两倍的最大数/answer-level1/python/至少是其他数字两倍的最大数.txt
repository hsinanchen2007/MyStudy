新建一个数组，nums 排序的结果赋值给它，如果最大的值是第二大的两倍则返回索引，否则返回 -1，可能第二大的是 0 所以这里我们用减法。如果只有一个数会抛异常，我们直接返回第一个索引即可。

```python
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        li = sorted(nums)
        try:
            return nums.index(li[-1]) if li[-1]-li[-2]>=li[-2] else -1
        except:
            return 0
```