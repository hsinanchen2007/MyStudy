### 解题思路
利用replace函数直接替换，替换前参数在前面，替换后的参数在后面。只针对要被替换的部分

### 代码

```python3
class Solution:
    def defangIPaddr(self, address: str) -> str:
        address_new = address.replace(".","[.]")
        return address_new
        
```