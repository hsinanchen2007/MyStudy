## 二分查找是基本的思路，问题是如何实现。
我们知道这里有一个index是旋转的坐标，我们只要找到了这个index就可以对index的两侧分别使用二分查找了。

## 如何实现index的查找

我们知道旋转后，index右边的元素都比左边的元素小，只要知道`mid = (left+right)//2``nums[mid+1]<nums[mid]`就可以知道index的值，如果不是则通过`nums[mid]>nums[left] or nums[mid]<nums[left]`来判断mix是否越过了index，得到index后对index两侧分别使用基础的二分查找算法即可。
```
class Solution(object):
    def search(self, nums, target):
        i = 0
        j = len(nums)-1
        temp = 0;
        while i<=j:
            mid = (i+j)//2
            if mid<len(nums)-1 and nums[mid+1]<nums[mid]:
                temp = mid+1
                break
            else:
                if nums[mid]>=nums[i]:
                    i = mid+1
                else:
                    j = mid-1
        left = self.mySearch(nums,target,0,temp)
        right = self.mySearch(nums,target,temp,len(nums))
        return max(left,right)
    def mySearch(self,nums,target,start,end):
        left = start
        right = end-1
        while left<=right:
            mid = (left+right)//2
            if nums[mid] == target:
                return mid
            elif nums[mid]>target:
                right = mid-1
            else:
                left = mid+1
        return -1;

```
