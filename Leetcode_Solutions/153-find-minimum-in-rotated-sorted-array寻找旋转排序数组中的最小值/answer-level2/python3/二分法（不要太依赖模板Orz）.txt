声明，代码是来自[water1111](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/discuss/158940/Beat-100%3A-Very-Simple-(Python)-Very-Detailed-Explanation)，英文好的建议直接去看，忽略以下。


这题带来的启示就是不要过度依赖模板...虽然模板有时候很有用。这里要求的是最小值，所以在`nums[mid] < nums[r]`时候（右侧有序，最小值在左侧或者`mid`处），`nums[r]`必然不是解，所以`r = mid`就是合理的范围缩减；同理`nums[mid] > nums[r]`的时候（右侧含有pivot, 最小值在右侧），`nums[mid]`必然不是最小值，所以`l = mid + 1`就是合理的范围缩减。此外，由于我们每一步都在进行范围缩减，所以我们一定会收敛到`l==r`而退出循环。又因为在每次缩减的过程中，我们并没有抛弃任何可能的最小值，所以最后必有`nums[l]=nums[r]=MIN`
```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = 0, n-1
        while l < r:
            mid = (l + r) // 2
            if nums[mid] < nums[r]:
                r = mid
            elif nums[mid] > nums[r]:
                l = mid + 1
        return nums[l]
```