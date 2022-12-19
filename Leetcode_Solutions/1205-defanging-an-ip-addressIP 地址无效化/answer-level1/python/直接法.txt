### 解题思路
直接用Python中的内置函数replace直接置换对应字符串

### 代码

```python
class Solution(object):
    def defangIPaddr(self, address):
        return address.replace(".","[.]")
```