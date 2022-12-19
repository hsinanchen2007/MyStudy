![二分查找算法1困难题目结果.png](https://pic.leetcode-cn.com/c8b04f11f008c8d7381f00eb864877b96b65aeda10b9708f7eed5b0323e142a5-%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE%E7%AE%97%E6%B3%951%E5%9B%B0%E9%9A%BE%E9%A2%98%E7%9B%AE%E7%BB%93%E6%9E%9C.png)

```
class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 以下皆为模板，详见《二分查找》的探索卡片模板二。
        left, right = 0, len(nums) - 1
        while left < right:
            mid = (left + right) >> 1
            # 仅有这一句判断是视情况而定添加的，针对的是[3, 3, 4, 1, 2, 3, 3, 3]这类情况。
            if nums[mid] == nums[left] and nums[mid] == nums[right]:
                right -= 1
                left += 1
            elif nums[mid] <= nums[right]:
                right = mid
            else:
                left = mid + 1
        return nums[left]
```
题目思考题讨论：
允许重复有可能会对时间复杂度造成影响。
- 在最坏情况下，即所有元素都是同一个数时，该算法的时间复杂度是O(N/2)，N是nums的元素个数。
- 在最好情况下，即所有元素都不重复时，该算法的时间复杂度是O(logN)。