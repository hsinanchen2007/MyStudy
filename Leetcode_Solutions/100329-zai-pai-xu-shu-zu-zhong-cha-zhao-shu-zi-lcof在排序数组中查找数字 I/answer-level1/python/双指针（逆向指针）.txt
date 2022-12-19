### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        count = 0
        l = 0 
        r = len(nums)-1
        while l<=r:
            m = (l+r)//2
            if nums[m]==target:
                count += 1
                i = m-1
                while i>=0:
                    if nums[i]==target:
                        count+=1
                        i-=1
                    else:
                        break 
                j = m+1
                while j<=len(nums)-1:
                    if nums[j]==target:
                        count+=1
                        j+=1
                    else:
                        break 
                break 
            if nums[m]>target:
                r = m-1
            if nums[m]<target:
                l = m+1
        return count 
```