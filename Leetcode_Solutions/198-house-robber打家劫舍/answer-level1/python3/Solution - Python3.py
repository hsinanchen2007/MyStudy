The official solution is clear enough. To reiterate, let $f(k)$ be the maximal amount of money you can get from the first $k$ houses. You have two choices for house $k$: you can either rob house $k$, which implies you have robbed house $k-2$, or else you have robbed house $k-1$ and so you do not rob $k$. You should choose the one with higher value. Thus we have the equation
$f(k) = \max\{f(k-2) + \texttt{A[k]}, f(k-1)\}$.

A Python3 solution is pasted below. Of course we can lower space usage from $O(n)$ to $O(1)$ by maintaining only two variables, but I hope this code can convey the spirit of dynamic programming to the audiance.

```
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        f = [nums[0], max(nums[0],nums[1])]
        for k in range(2, n):
            f.append(max(f[k-2]+nums[k], f[k-1]))
        return f[-1]
```
