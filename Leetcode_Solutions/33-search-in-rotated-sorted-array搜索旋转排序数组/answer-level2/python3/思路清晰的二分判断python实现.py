### 解题思路
首先判断mid位于左边还是右边，然后在两边已经排好序的数组中查找target.
### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l,r = 0,len(nums)-1
        if len(nums)==0:
            return -1
        while l<r:
            mid = l+(r-l)//2
            if nums[mid]<nums[r]: #mid位于右边
                if nums[mid]<target and target<=nums[r]: #(mid,r]
                    l = mid+1
                else: #[l,mid]
                    r = mid
            else: #mid位于左边
                if nums[mid]>=target and target>=nums[l]: #[l,mid]
                    r = mid
                else: # (mid,r]
                    l = mid+1
        return l if nums[l]==target else -1
```