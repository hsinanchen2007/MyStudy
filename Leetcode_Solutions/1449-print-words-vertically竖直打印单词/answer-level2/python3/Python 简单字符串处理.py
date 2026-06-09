![image.png](https://pic.leetcode-cn.com/46aaffea019565978398921a00b29cf2d82706d43d2b7646efe07f80c4833dcd-image.png)


```
'''
顺次组装各个字符串同一个位置的字符，然后去掉组装字符串尾巴上的空格
'''


from typing import List
class Solution:
    def printVertically(self, s: str) -> List[str]:
        str_arr = s.split(' ')
        max_len = max([len(x) for x in str_arr])

        ret = []
        for row in range(0, max_len):
            ans = ''
            for s in str_arr:
                if row < len(s):
                    ans = ans + s[row]
                else:
                    ans = ans + ' '
            ans = ans.rstrip()
            ret.append(ans)

        return ret

```
