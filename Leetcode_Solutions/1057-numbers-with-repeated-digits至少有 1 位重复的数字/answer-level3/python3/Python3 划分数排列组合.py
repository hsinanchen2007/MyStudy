
[@wafer-2](/u/wafer-2)参考这位朋友的评论以及他提及的原评论

[@lee215](/u/lee215) [原题解](https://leetcode.com/problems/numbers-with-repeated-digits/discuss/256725/JavaPython-Count-the-Number-Without-Repeated-Digit)

自己基于上述理解Python3编程实现，48ms，击败了90%的Python3提交

```
import functools

class Solution:
    def numDupDigitsAtMostN(self, N: int) -> int:
        arr = [int(s) for s in str(N+1)]
        res, l = 0, len(arr)

        @functools.lru_cache()
        def A(m, n):
            if n == 0:
                return 1
            else:
                return A(m, n-1) * (m-n+1)

        for i in range(1, l):
            res += 9 * A(9, i-1)

        # print(res)

        s = set()
        for i, num in enumerate(arr):
            for j in range(0 if i else 1, num):
                if j not in s:
                    res += A(9-i, l-1-i)
                    # print(res)
            if num in s:
                break
            s.add(num)
            # print("set", s)
        return N - res

```