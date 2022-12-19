### 解题思路
注意本题是基于一个升序数组进行旋转的，如`[1,2,3,4,5]`，分别可以旋转成`[2,3,4,5,1],[3,4,5,1,2],[4,5,1,2,3],[5,1,2,3,4],[1,2,3,4,5]`这5种情况，不可能旋转成倒序数组的；因此不需要考虑倒序的测试样例；

1. 如果`nums[0]<nums[-1]`，则表明`nums`数组为升序排序，则最小值即为`nums[0]`；
2. 否则通过二分法进行搜索：`left=0, right=len(nums)-1, mid=(left+right)>>1`；如果`nums[mid]<nums[right]`，则表明最小值在`nums[left:mid+1]`中；如果`nums[mid]>=nums[left]`，则表明最小值在`nums[mid+1:right+1]`中；

### 代码

```python3
class Solution:
    """
    二分法寻找：
    1. 如果left < right（即没有旋转，为升序数组）, 则最小值即为left；
    2. left, right, mid, 如果mid > left, 则最小值肯定在mid+1与right之间；如果mid<right, 则最小值肯定在left与mid之间；

    """
    def findMin(self, nums) -> int:
        if len(nums) == 0:
            return None

        if nums[-1] > nums[0]:
            return nums[0]

        left, right = 0, len(nums)-1
#        两种判断方式；
#        while left < right:
#            mid = (left+right)>>1
#            这里要先判断是否小于nums[right]
#            if nums[mid] < nums[right]:
#                right = mid
#            elif nums[mid] >= nums[left]:
#                left = mid+1
#        return nums[left] if nums[left]<nums[right] else nums[right]
        while right-left != 1:
            mid = (left+right)>>1
            if nums[mid] > nums[left]:
                left = mid
            elif nums[mid] < nums[right]:
                right = mid
        return nums[left] if nums[left]<nums[right] else nums[right]
```