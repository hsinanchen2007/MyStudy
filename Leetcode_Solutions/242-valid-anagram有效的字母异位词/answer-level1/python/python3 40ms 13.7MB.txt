### 解题思路
1. 先用set去重，查看去重后是否相同，不相同直接返回false
2. 对去重后的集合遍历去查询出现的次数，for循环结束都都为true，返回true

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_set = set(s)
        t_set = set(t)
        result = True
        if s_set != t_set:
            return False
        else:
            for i in s_set:
                result = result and (s.count(i) == t.count(i))
            return result
```