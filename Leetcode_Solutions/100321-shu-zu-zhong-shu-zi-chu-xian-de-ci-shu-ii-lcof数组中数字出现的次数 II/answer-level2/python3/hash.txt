### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        dic  ={}
        for i in range(len(nums)):
            if nums[i] not in dic:dic[nums[i]] = 1
            else:
                dic[nums[i]] += 1
                if dic[nums[i]]==3:dic.pop(nums[i]) 
                
        return list(dic.keys())[0]
```