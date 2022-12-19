### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(n):
            if '0' not in str(i) and '0' not in str(n-i):
                return [i,n-i]
```