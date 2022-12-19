### 解题思路
约瑟夫环问题，经典倒着想的问题，有助于后脑勺开发。

### 代码

```python3
class Solution():
    def lastRemaining(self, n, m):
       return 0 if n==1 else (m+self.lastRemaining(n-1, m))%n
```