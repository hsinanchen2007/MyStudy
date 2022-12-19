### 解题思路
首先利用二分法寻找旋转中心点，再在对应区域用二分法寻找target。注意分界点的独立情况。

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def find_rotate_index(left, right):
            if nums[left]<nums[right]:
                return 0
            while left<=right:
                mid = (left+right)//2
                if nums[mid]>nums[mid+1]:
                    return mid+1
                else:
                    if nums[mid]<nums[left]:
                        right = mid-1
                    else:
                        left = mid +1
        def search(left, right):
            while left<=right:
                mid = (left+right)//2
                if nums[mid] == target:
                    return mid
                else:
                    if nums[mid]>target:
                        right = mid-1
                    else:
                        left = mid+1
            return -1
        
        n = len(nums)
        if n == 0:
            return -1
        if n ==1:
            return 0 if nums[0]==target else -1
        rotate_index = find_rotate_index(0, n-1)
        if nums[rotate_index]==target:
            return rotate_index
        if rotate_index==0:
            return search(0, n-1)
        if nums[0]>target:
            return search(rotate_index, n-1)
        return search(0,rotate_index)


        
```