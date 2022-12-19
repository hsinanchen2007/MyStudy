### 解题思路
不知道加负无穷符不符合题意

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        j=1
        if not nums:
            return 0
        for i in range(len(nums)-1):
            while(1):
                if nums[i]==nums[i+1]:
                    nums.pop(i+1)
                    nums.append(-float('inf'))
                elif nums[i]<nums[i+1]:
                    j=j+1
                    break
                else:
                    return j
        return j
        
```