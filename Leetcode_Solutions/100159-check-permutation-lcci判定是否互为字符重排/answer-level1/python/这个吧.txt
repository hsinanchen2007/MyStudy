### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        a = sorted(s1)
        b = sorted(s2)
        return a == b


    
        
```