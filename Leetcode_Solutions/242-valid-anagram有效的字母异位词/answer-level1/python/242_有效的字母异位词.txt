### 解题思路
1. 对字符串进行一下过滤
2. 字符串转列表
3. 列表排序
4. 对比

直接使用  collections 里的 Counter 方法更好

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if s is None and t is None:
            return False
        if len(s) != len(t):
            return False
        list_s = list(s)
        list_t = list(t)
        list_s.sort()
        list_t.sort()
        if list_s == list_t:
            return True
        if list_s != list_t:
            return False
```