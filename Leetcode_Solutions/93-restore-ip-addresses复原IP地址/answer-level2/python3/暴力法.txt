### 解题思路
此处撰写解题思路
将字符串分成四段，每段进行有效检查：如果是0的话只能有一位，如果不是0的话首位不能是0
### 代码

```python3
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        def is_vaild(s):
            if int(s) == 0 and len(s) >1 or s[0] =="0" and len(s) >1:
                return False
            if 0 <= int(s) <= 255:
                return True
            else:
                return False

        res = set()
        for a in range(1, 4):
            for b in range(1, 4):
                for c in range(1, 4):
                    for d in range(1, 4):
                        if a + b + c + d == len(s):
                            seg1 = s[:a]
                            seg2 = s[a:a + b]
                            seg3 = s[a + b:a + b + c]
                            seg4 = s[a + b + c:a + b + c + d]
                            seg = [seg1, seg2, seg3, seg4]
                            if is_vaild(seg1) and is_vaild(seg2) \
                            and is_vaild(seg3) and is_vaild(seg4):
                                res.add(".".join(seg))
        return list(res)

```