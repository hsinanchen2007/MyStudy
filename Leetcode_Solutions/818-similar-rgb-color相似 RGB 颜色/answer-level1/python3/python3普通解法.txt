```
class Solution:
    def similarRGB(self, color: str) -> str:
        r, g, b = int(color[1:3], 16), int(color[3:5], 16), int(color[5:], 16)
        res = '#'

        def helper(c):
            dd = [0] * 2
            while True:
                for d in dd:
                    ans = c + d
                    if ans % 16 == ans // 16:
                        ans = format(ans, 'x')
                        if ans == '0':
                            return ans + '0'
                        else:
                            return ans
                dd[0] += 1
                dd[1] -= 1

        res += helper(r) + helper(g) + helper(b)
        return res
```
