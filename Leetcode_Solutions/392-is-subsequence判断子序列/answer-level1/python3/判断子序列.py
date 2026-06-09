### 解题思路
有两种思路：
1. 遍历t，如果找到某一个t里的元素，它等于s[0]，则将s[0]移除，如果最后s为空，则True
2. 遍历s，如果在t里某个位置找到s的元素，则截取该位置后面的列表，继续遍历，如果遍历完s，每一个s里的元素都在t里找到，则True

### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        s = list(s)
        for _t in t:
            if not s:
                return True
            if _t == s[0]:
                s.pop(0)
        return not s

# 作者：leicj
```