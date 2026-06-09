首先想到的是直接利用Counter
其次想到的是二分法

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # 直接利用Counter
        c = collections.Counter(nums)
        times = c.get(target)  # 获得target出现的次数
        if times:
            return times
        return 0

        # 或者利用二分法
        # 排序数组中的搜索问题，可以利用 二分法 解决
        # n = len(nums)
        # l = 0
        # r = n - 1
        # while l <= r:
        #     mid = (l + r) // 2
        #     if nums[mid] <= target:
        #         l = mid + 1
        #     else:
        #         r = mid - 1
        # right = l
        # n = len(nums)
        # l = 0
        # r = n - 1
        # while l <= r:
        #     mid = (l + r) // 2
        #     if nums[mid] < target:
        #         l = mid + 1
        #     else:
        #         r = mid - 1
        # left = r
        # return right - left - 1
```