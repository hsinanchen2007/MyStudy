### 解题思路
利用set的去重特性，检查去重后字符串长度和去重前长度是否一致

### 代码

```python3
class Solution:
    def isUnique(self, astr: str) -> bool:
        return len(set(list(astr))) == len(list(astr))

```