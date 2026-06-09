### 解题思路
int和str之间的转换，避免进位

### 代码

```python3
class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        strA = [str(item) for item in A]
        res = int(''.join(strA)) + K
        return [item for item in str(res)]
        
```