进行一次循环，同时遍历left和right，right每往右一位就乘，left每往右一位就除，过程中累计不大于k的res。即在left右移时不要刷新mul乘积，而是除以去掉的left，这样能保证不浪费之前得出的乘积结果。

```
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k<=1:
            return 0
        #从左往右遍历，双指针保存位置
        right=left=res=0
        l=len(nums)
        mul=1
        while left < l:
            while right < l and mul*nums[right] < k:
                mul*=nums[right]
                right+=1
            if(right <= left):
                # mul=1,题目里说明了数元素不可能是0，因此即便双指针相遇，也不用刷新mul
                left=left+1
                right=left
            else:
                res+=right-left
                mul/=nums[left]
                left+=1
        return res
```

    

            