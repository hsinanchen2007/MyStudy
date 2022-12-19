### 解题思路
直接替换

### 代码

```python3
class Solution:
    def defangIPaddr(self, address: str) -> str:
        return address.replace('.', '[.]')
```