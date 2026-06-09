### 解题思路
用个replace方法就搞定了。。

### 代码

```python3
class Solution:
    def defangIPaddr(self, address: str) -> str:
        L = address.replace('.', '[.]')
        return L
```