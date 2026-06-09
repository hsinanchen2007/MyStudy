### 解题思路
使用双指针，left,right 从两头遍历，遇到nums[left]为偶数，nums[right]为奇数时候，交换。

### 代码

```python3
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        left,right=0,len(nums)-1
        while left <right:
            while left <right and nums[left]%2!=0:
                left+=1
            while left <right and nums[right]%2==0:
                right-=1
            nums[left],nums[right]=nums[right],nums[left]
            left+=1
            right-=1
        return nums

```