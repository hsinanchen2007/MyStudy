### 解题思路
开始还以为自己想简单了。。。

### 代码

```python3
class Solution:
    def generateTheString(self, n: int) -> str:
        if n % 2:
            return 'a'*n
        else:
            return 'a'*(n-1) + 'b'
```