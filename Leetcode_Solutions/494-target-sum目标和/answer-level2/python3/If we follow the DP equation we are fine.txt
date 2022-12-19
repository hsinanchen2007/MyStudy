Let $x$ be the sum of positive terms, and let $y$ be the sum of the negative terms. We want
$\displaystyle \begin{cases}x - y = S\\ x + y = \texttt{sum(nums)}\end{cases} \Rightarrow 2x = S + \texttt{sum(nums)} \Rightarrow x = \frac{S + \texttt{sum(nums)}}{2}.$

The problem then becomes: select some elements from the input array so that they sum to target `(sum(nums) + S) // 2`. Return the count of all such possible selections.

Let $f(i, j)$ be the # of ways for input `nums[:i+1]` and target `j`. We can either use `nums[i]`, or not use it. If we do not use `nums[i]`, then there are $f(i - 1, j)$ ways of summing to the target `j`. On the other hand, how many ways are there if `nums[i]` must be used? This is equal to the # of ways of summing up to `j - nums[i]` in the array `nums[:i]`, i.e. $f(i - 1, j - \texttt{nums[i]})$. Thus, $f(i, j)$ is equal to the sum of the two counts:

$f(i, j) = f(i - 1, j) + f(i - 1, j - \texttt{nums[i]})$.

We can then write out the program following the DP equation. See below. There is one way of summing `nums[0]` to $0$, namely not pick the element, so we initialize `f[0]` as $1$. The terms involving `i` on the right hand side of the equation are the same ($i-1$), so we drop variable $i$ and use one-dimensional array to store values of $f$. 
```
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        if sum(nums) < S or (sum(nums) + S) % 2 == 1: return 0
        target = (sum(nums) + S) // 2
        f = [1] + [0 for _ in range(target)]
        for i in range(len(nums)):
            for j in range(target,nums[i] - 1, -1):
                f[j]  = f[j] +  f[j - nums[i]]
        return f[target]
```

Note that the equation as well as the code are almost the same to that in the [partition equal subset sum](https://leetcode-cn.com/problems/partition-equal-subset-sum/) problem. See [my post on that problem](https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/if-we-have-the-dp-equation-then-everything-is-fine/). I copy the DP equation for the partition equal subset sum problem here:

$f(i, j) = f(i - 1, j) \vee f(i - 1, j - \texttt{nums[i]})$.

We can see that $+$ corresponds to $\vee$. One function is numerical, the other has binary output. They have the same structure because the two problems are essentially the same 0-1 knapsack problem.