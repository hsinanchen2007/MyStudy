### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def grayCode(self, n: int) -> List[int]:
        res = []
        def convert(s):
            return int(s, 2)
        def helper(n):
            if n == 0:
                return ['0']
            if n == 1:
                return ['0', '1']
            else:
                return ['0' + s for s in helper(n - 1)] +  ['1' + s for s in helper(n - 1)][::-1]
        return list(map(convert, helper(n)))
        
```