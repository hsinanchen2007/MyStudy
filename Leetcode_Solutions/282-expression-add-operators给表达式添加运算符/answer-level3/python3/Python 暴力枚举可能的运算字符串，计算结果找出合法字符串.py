

```
import re
from typing import List
from functools import lru_cache
class Solution:

    #  乘法计算
    @lru_cache(typed=False)
    def calc_mul(self, s: str):
        vals = re.split(r'[*]', s)
        ans = 1
        for val in vals:
            ans *= int(val)
        return ans

    @lru_cache(typed=False)
    def calc(self, s: str):
        vals = re.split(r'[+\-]', s)
        opers = [ch for ch in s if ch in ['+', '-']]

        ans = self.calc_mul(vals[0])
        for i, oper in enumerate(opers):
            if oper == '+':
                ans += self.calc_mul(vals[i+1])
            else:
                ans -= self.calc_mul(vals[i+1])

        #print(s, vals, opers, ans)
        return ans


    def build_str(self, cur: int, s: str, path: List[str], target: int, ans: List[str]):
        n = len(s)
        if cur == n:
            calc_str = ''.join(path)
            if self.calc(calc_str) == target:
                ans.append(calc_str)

            return

        if cur == 0:
            for i in range(1, n+1):
                if i >= 2 and s[0] == '0':
                    continue

                path.append(s[0:i])
                self.build_str(i, s, path, target, ans)
                path.pop(-1)
        else:
            for i in range(cur+1, n+1):
                for oper in ['+', '-', '*']:
                    if i >= cur+2 and s[cur] == '0':
                        continue

                    path.append(oper + s[cur:i])
                    self.build_str(i, s, path, target, ans)
                    path.pop(-1)


    def addOperators(self, num: str, target: int) -> List[str]:
        if num == '':
            return []

        ans = []
        self.build_str(0, num, [], target, ans)
        return ans
```
