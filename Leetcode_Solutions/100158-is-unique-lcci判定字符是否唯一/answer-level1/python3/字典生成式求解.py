### 解题思路
1.利用字典生成式，把字符串的每个字母作为Key，出现次数为value
2.排除value小于1的值，若为空字典，则说明没有重复值

### 代码

```python3
class Solution:
    def isUnique(self, astr: str) -> bool:
        return {k:list(astr).count(k) for k in list(astr) if list(astr).count(k) >1  } == {}
```