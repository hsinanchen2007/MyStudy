### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def expand(self, S: str) -> List[str]:
        def generate(s, tmp):
            if not s:
                res.append(tmp[:])
                return
            if s[0].isalpha():
                generate(s[1:], tmp + s[0])
            else:
                for i in range(len(s)):
                    if s[i] == "}":
                        substring = s[1:i]
                        break
                chars = substring.split(",")
                chars.sort()
                for char in chars:
                    generate(s[i + 1:], tmp + char)
        res = []
        generate(S, "")
        return res
```