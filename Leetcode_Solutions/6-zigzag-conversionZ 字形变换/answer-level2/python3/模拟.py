```py3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        from collections import  defaultdict
        rows = defaultdict(list)
        up = False
        i = 0
        while i < len(s):
            if i < numRows:
                rows[i].append(s[i])
            else:
                if (i - numRows) % (numRows - 1) == 0:
                    if up:
                        up = False
                        cnt = 1
                    else:
                        up = True
                        cnt = numRows - 2
                if up:
                    rows[cnt].append(s[i])
                    cnt -= 1
                else:
                    rows[cnt].append(s[i])
                    cnt += 1
            i += 1
        ans = ""
        for k, v in rows.items():
            ans += "".join(v)

        return ans
```