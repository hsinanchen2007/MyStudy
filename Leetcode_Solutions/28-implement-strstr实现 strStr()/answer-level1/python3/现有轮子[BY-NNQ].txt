### 解题思路
> 先用一下现有的轮子， 后面再手工造一个Sunday算法的；

### 代码

```python3 [group1-python3函数find]
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)
```

```python3 [group1-python3之SundaySearch]
def SundaySearch(s, p):
    # todo
    pass

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return SundaySearch(haystack, needle)
```

### time
```
# find
执行用时 :36 ms, 在所有 Python3 提交中击败了73.64%的用户
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了5.10%的用户

------
# SundaySearch

```