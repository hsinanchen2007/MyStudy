### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        dict={}
        for i,num in enumerate(numbers):
            dict[num] = i
        for j in range(len(numbers)):
            tmp = target-numbers[j]
            if (tmp in dict and dict[tmp]!=j):
                return [j+1,dict[tmp]+1]
        return False
```