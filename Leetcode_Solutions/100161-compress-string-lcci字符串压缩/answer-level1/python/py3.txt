### 解题思路
使用字典保存当前遍历的字符次数，遇到不相同的字符弹出字典中的值，更新s

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return S
        rel = dict()
        s = ""
        for i in S:
            if i in rel.keys():
                rel[i] += 1
            else:
                if rel:
                    _s = rel.popitem()
                    s += ''.join([_s[0], str(_s[1])])
                rel[i] = 1
        if rel:
            for k, v in rel.items():
                s += ''.join([k, str(v)])

        return s if len(s) < len(S) else S
```