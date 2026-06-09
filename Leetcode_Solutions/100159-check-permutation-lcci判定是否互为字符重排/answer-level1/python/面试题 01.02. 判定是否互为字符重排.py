### 解题思路

### 代码

```python3
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2): return False
        ls2 = list(s2)
        for i in s1:
            if i in ls2:
                ls2.remove(i)
            else:
                return False
        return True 
                

```