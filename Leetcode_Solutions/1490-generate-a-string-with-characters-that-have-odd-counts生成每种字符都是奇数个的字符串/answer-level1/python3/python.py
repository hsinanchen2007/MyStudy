### 解题思路
如果 n为偶数，返回n-1个'a'，1个'b'
如果 n为奇数，返回n个奇数

### 代码

```python3
class Solution:
    def generateTheString(self, n: int) -> str:
        if n%2 == 0:
            return 'a'*(n-1) + 'b'
        else:
            return 'a'*n
```