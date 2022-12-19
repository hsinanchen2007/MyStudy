### 解题思路
python 一行

### 代码

```python3
class Solution:
    def defangIPaddr(self, address: str) -> str:
        return address.replace('.', '[.]')
```