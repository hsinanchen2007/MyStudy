### 解题思路
遍历 字符串t 通过 count函数 分别计算 t 和 s 中字母数量，若数量不同，则是 t 中被添加的字母。

### 代码

```python3
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        for i in t:
            t_count = t.count(i)
            s_count = s.count(i)
            if t_count != s_count:
                return i

```