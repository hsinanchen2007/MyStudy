字符串分割成两块，分别对每一块进行判断，一共有四种情况
1.首尾均是0，违规；
2.首0，只有一种情况，即0.XXX
3.尾0，只有一种情况，即XXXX0
4.其他的每个间隔位均可插入0

```
import itertools
class Solution:
    def ambiguousCoordinates(self, S: str) -> List[str]:
        def panduan(s):

            if len(s) == 1:
                return [s]
            elif s[0] == '0' and s[-1] == '0':
                return None
            elif s[0] == '0':
                return [s[0] + '.' + s[1:]]
            elif s[-1] == '0':
                return [s]
            else:
                return [s[:i]+'.'+s[i:]  for i in range(1,len(s))] + [s]

        S = S[1:-1]
        n = len(S)
        output = []
        for i in range(1,n):
            s1 = panduan(S[:i])
            s2 = panduan(S[i:])
            if s1 and s2:
                for i,j in itertools.product(s1,s2):
                    output.append('(' + ', '.join([i,j]) + ')')
        return output
```
