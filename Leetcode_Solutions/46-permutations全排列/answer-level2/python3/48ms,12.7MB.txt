### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
    
        now_index = []
        for i in range(len(nums)):
            now_index.append([i])
    
        result = []
        while len(now_index) > 0:
            next_index = []
            for i in range(len(now_index)):
                flag = 0
                if len(now_index[i]) != len(nums):
                    for j in range(len(nums)):
                        if j not in now_index[i]:
                            next_index.append(now_index[i] + [j])
                            flag = 1
                else:
                    if flag == 0:
                        result.append(now_index[i])
            now_index = next_index
    
        finally_result = []
        for i in result:
            finally_result.append([nums[j] for j in i])
    
        return finally_result
```