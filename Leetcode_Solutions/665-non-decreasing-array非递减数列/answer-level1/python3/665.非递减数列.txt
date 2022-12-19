### 解题思路
- 从头开始遍历，当前位置要小于下一位置，否则需要处理（这也意味着处理当前位置时，前一位置必定小于等于当前位置（天然或处理得到无所谓）
- 当前位置i,如果a[i-1]<a[i+1],修改a[i]=a[i-1]即可（最克制）满足非递减
- 当前位置i,如果a[i-1]>a[i+1],修改a[i+1]=a[i]即可（最克制）满足非递减 (a[i]>a[i-1]是肯定的！)
- 
### 代码

```python3
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        if len(nums)<2:
            return True
        flag = 0
        for i in range(0,len(nums)-1):
            if nums[i]>nums[i+1]:
                if i-1<0:
                    nums[i]=nums[i+1]
                    flag = flag + 1
                elif nums[i-1]<=nums[i+1]:
                    nums[i]=nums[i+1]
                    flag = flag + 1
                elif nums[i-1]>nums[i+1]:
                    nums[i+1]=nums[i]
                    flag = flag + 1
                if flag >1:
                    return False
            
        return flag <= 1
```