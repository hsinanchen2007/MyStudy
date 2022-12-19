就是递归打出目标集合内的数字组合，再与N比较。
代码还存在不少优化空间，复杂度O(7^(logN+1))，对于大数是比O(N)快的。
```
import re
class Solution:
    def rotatedDigits(self, N: int) -> int:
        l = len(str(N))
        st = set()

        def helper(s, i):
            if len(s) > l:
                return
            elif len(s) == l:
                if int(s) <= N and re.search("[2569]", s):
                    st.add(int(s))
            else:
                for j in ("0", "1", "2", "5", "6", "8", "9"):
                    helper(s + j, i + 1)

        helper("", 0)
        return len(st)
```
