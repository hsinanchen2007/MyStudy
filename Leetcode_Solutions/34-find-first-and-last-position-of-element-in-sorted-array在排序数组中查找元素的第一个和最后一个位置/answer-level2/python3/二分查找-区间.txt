### 解题思路

* 在[704. 二分查找](https://leetcode-cn.com/problems/binary-search/)和[35. 搜索插入位置](https://leetcode-cn.com/problems/search-insert-position/)两题中，数组不包含重复元素，我们使用二分搜索进行值的查找。该题的数组可能包含重复元素，因此这里搜索的是一个区间。
* 本能的做法是先用二分找到该值的某个位置，然后向前和向后进行线性搜索，但这样一来，最差的时间复杂度为O(N)。
* 所以，在这里，我们建立`left_index`和`right_index`两个变量，动态更新区间的左右位置。当找`left_index`时，如果`nums[mid] == target`，先让`left_index = mid`存着，然后继续搜左半边，看看还有没有更前边的。同理，寻找`right_index`时也是一样der。
* 时间复杂度: O(logN); 空间复杂度: O(1)

### 代码

```python []
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left_index, right_index = -1, -1

        left, right = 0, len(nums)-1
        while(left <= right):
            mid = left + (right - left)//2
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                left_index = mid
                right = mid - 1
        
        left, right = 0, len(nums)-1
        while(left <= right):
            mid = left + (right - left)//2
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                right_index = mid
                left = mid + 1
        
        return [left_index, right_index]
```