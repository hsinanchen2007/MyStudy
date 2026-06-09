思路：查看去除重复字符后的astr和原来的astr的len是否相等即可
```
class Solution:
    def isUnique(self, astr: str) -> bool:
        return len(astr)==len(set(astr))
```
