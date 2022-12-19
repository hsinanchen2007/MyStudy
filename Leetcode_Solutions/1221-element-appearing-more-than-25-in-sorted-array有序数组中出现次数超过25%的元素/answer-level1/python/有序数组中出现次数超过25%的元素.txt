### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        length = len(arr)
        dic = collections.Counter(arr)
        for key,value in dic.items():
            if (value / length) > 0.25:
                return key
        
      
```