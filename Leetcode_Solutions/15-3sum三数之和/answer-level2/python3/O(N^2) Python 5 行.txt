```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums, r = sorted(nums), set()
        for i in [i for i in range(len(nums)-2) if i < 1 or nums[i] > nums[i-1]]:
            d = {-nums[i]-n: j for j, n in enumerate(nums[i + 1:])}
            r.update([(nums[i], n, -nums[i]-n) for j, n in enumerate(nums[i+1:]) if n in d and d[n] > j])
        return list(map(list, r))
```
- 时间复杂度：O(N^2)
- 这里 sort 一是为了避免重复，这一点可以体现在我们输出的结果都是升序的，如果不这么做 set 无法排除一些相同结果，而是为了节省计算，防止超时
- for 循环内部的代码思想同` 第一题 Two Sum`，用字典记录｛需要的值:当前索引｝，如果字典中存在相同的数字，那么将会记录比较大的那个索引，因此可以用`d[n] > i`来避免一个元素重复选择
- `(nums[i], n, -nums[i]-n)`保证了列表升序
