### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        is_ok = True
        for j in range(1, len(s)):
            lens = j
            count = len(s) / lens
            is_ok = True
            if count != len(s) // lens:
                continue
            substr = s[0:j]
            # 方案1) 以此往后移动，比较字符串和substr相同
            # for k in range(0, len(s) // lens):
            #     substr2 = s[(lens * k):(lens * k + lens)]
            #     if substr != substr2:
            #         is_ok = False
            #         break
            # if is_ok:
            #     return True
            # 方案2）用substr重新构造字符串，看是否与原来的s相等
            if substr * (len(s) // lens) == s:
                return True

        return False
```