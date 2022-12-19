```
def gck(a, b):
    while b != 0:
        a, b = b, a % b
    return a

class Solution(object):
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        d = {}
        for _ in deck:
            if _ in d:
                d[_] += 1
            else:
                d[_] = 1

        vs = d.values()
        if len(d) == 1:
            return vs[0] > 1

        vs = iter(vs)
        g = vs.next()
        for v in vs:
            g = gck(g, v)
            if g == 1:
                return False
        return True

```
把问题抽象出来就是，数字出现的次数有没有>=2的最大公约数。

