### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:

        for i in range(len(s)):
            if "()" in s:
                s = s.replace("()", "")
            if "[]" in s:
                s = s.replace("[]", "")
            if "{}" in s:
                s = s.replace("{}", "")

        if s == "":
            return True
        else:
            return False
```