# 1.对于一个公差为1的等差数列，已知数量n ,可用公式 target=n*a1+n*(n-1)/2,求得a1
```
 math import sqrt


class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        ls = []

        def solve_n(a1, target):
            return 0.5 * (1 - 2 * a1 + sqrt(4 * (a1 ** 2) - 4 * a1 + 1 + 8 * target))

        for a1 in range(1, target // 2+1):
            n = solve_n(a1, target)


            if int(n)==n:
                ls.append([x + a1 for x in range(int(n))])
        return ls 
```
