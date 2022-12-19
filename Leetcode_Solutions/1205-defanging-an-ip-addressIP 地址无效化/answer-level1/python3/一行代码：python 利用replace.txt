### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def defangIPaddr(self, address: str) -> str:
        return address.replace(".","[.]")
            
```