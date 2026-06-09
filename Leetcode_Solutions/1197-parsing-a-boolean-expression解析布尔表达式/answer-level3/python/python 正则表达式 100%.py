练习算法的话不推荐用，快速过题可以用用
```
import re
class Solution:
    def parseBoolExpr(self, s):
        while len(s) > 1:
            s = re.sub(r'!\(f\)|\|\([^()]*t[^()]*\)|&\([t,]*\)', 't', \
                       re.sub(r'!\(t\)|&\([^()]*f[^()]*\)|\|\([f,]*\)', 'f', s))
        return s == 't'
```
