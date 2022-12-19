回到最基础的二分查找过程，原本的二分查找，我们只关心找到没找到，返回True或者 False。
```
left,right=....
while left <= right:
    mid = (left+right) >> 1
    if nums[mid] == target:
        return True
    elif nums[mid] < target:
        left = mid + 1
    elif nums[mid] > target:
        right = mid - 1

return False
```
对于本题，我们找到了直接返回下标，就是插入位置，那要是没找到呢？

我们看看二分查找没命中是什么情况：

二分查找，如果查找不到target的话，跳出循环时，会有left > right，即left=right+1

这个时候对应两种情况:

- 一种是由于`nums[mid]<target`导致`left=mid+1`跳出，此时
    `nums[left-1]<target<nums[left]`
- 一种是由于 `nums[mid]>target`导致`right=mid-1`跳出，此时`nums[right]<target<nums[right+1]` 而left=right+1,即也是nums[left-1]<target<nums[left]

即不论什么情况，只要没有检索到目标值，那么target一定介于`left-1`和`left`之间，对应插入位置就是`left`

所以直接返回`left`就可以了。

```
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left = 0
        right = len(nums)-1

        while left <= right:
            mid = (right+left)>>1
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
        
        return left
```

顺便打个小广告，自己最近找实习，搭了一个小博客用来记录下，实习面经 以及一些实习中用到的技能点
[Mereder](https://mereder.github.io)


