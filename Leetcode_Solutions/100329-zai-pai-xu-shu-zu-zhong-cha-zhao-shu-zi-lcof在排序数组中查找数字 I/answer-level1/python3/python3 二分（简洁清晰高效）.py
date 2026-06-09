### 解题思路
![截屏2020-03-04下午3.55.55.png](https://pic.leetcode-cn.com/b60ad2c51a6e0831cc9b0b37281a99de12775d8afcccd2d4224daf305495813a-%E6%88%AA%E5%B1%8F2020-03-04%E4%B8%8B%E5%8D%883.55.55.png)


### 代码


```python []
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums: return 0
        left, right = 0, len(nums)-1
        while left + 1 < right:
            mid = (left + right) >> 1
            if nums[mid] < target:
                left = mid
            else:
                right = mid
        count, end = 0,len(nums)-1
        if nums[left] == target:
            while left <= end and nums[left] == target :
                left += 1
                count += 1
            return count
        elif nums[right] == target:
            while right <= end and nums[right] == target:
                right += 1
                count += 1
            return count
        else: return 0
```
[更多内容，欢迎关注简书](https://www.jianshu.com/p/9cbdda8a3e5e)