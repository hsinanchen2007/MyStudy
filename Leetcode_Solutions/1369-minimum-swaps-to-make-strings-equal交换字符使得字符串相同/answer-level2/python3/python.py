![QQ图片20191104214339.png](https://pic.leetcode-cn.com/a877b4a85d4fc8f2a9888ce31939b740829642127fa25c00b961000d0870ed40-QQ%E5%9B%BE%E7%89%8720191104214339.png)
```
class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        count = {'x': 0, 'y': 0}
        for c1, c2 in zip(s1, s2):
            if c1 != c2:
                count[c1] += 1
        count_x = count['x']
        count_y = count['y']
        if (count_x + count_y) & 1:
            return -1
        else:
            return (count_x >> 1) + (count_y >> 1) + ((count_x & 1) << 1)
```
