### 解题思路
核心思想 cur_max_value[i] = max(cur_max_value[i-1],cur_max_value[i-2]+nums[i])

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        cur_max_value = []
        if nums == []:
            return 0
        for i,item in enumerate(nums):
            if i == 0:
                cur_max_value.append(item)
            elif i == 1:
                cur_max_value.append(self.max_value(nums[0],nums[1]))
            else:
                cur_max_value.append(self.max_value(cur_max_value[i-1],cur_max_value[i - 2] + nums[i]))
        
        return cur_max_value.pop()

    def max_value(self,a,b):
        if a > b:
            return a
        return b           
                 
```