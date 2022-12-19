### 解题思路
计算资源很不稳定呀~~，测试是40ms； 提交的时候时间是36ms~~ 

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap={}
        for ind,num in enumerate(nums):
            j = hashmap.get(target - num)
            if j is not None :
                return [ind,j]
            hashmap[num] = ind
            
```