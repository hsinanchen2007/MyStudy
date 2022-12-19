本题要求:计算最小的工作计划难度.结果可以用下列式子来表达:
$$
    mD(jobs, d) = \sum_{i=1}^{d}max(job\in D_i) 
$$
$$
= max(job\in D_1) + \sum_{i=2}^{d}max(job\in D_i)
$$
因为job必须按照顺序完成且每天至少完成一个工作, 所以$D_1$(第一天), 所以可以完成 $1$ 个, $2$ 个一直到 $n-d+1$ 个工作.令$S(D_1)={1, 2...n-d+1}$, $S(D_1^{rest})={job not in D_1}$

$$
md(jobs, d) = min_{S(D_1)}(max(job \in D_1) + md(D_1^{rest}, d - 1))
$$
通过上述公式可以,简单的求解出问题的解

```
class Solution:
    def minDifficulty(self, jD: List[int], d: int) -> int:
        if len(jD) < d: return -1
        memo = {}
        def dp(memo, jD, i, d): # 求解mD(jD[i:], d)
            if len(jD) - i  < d: return -1
            if d == 1: return max(jD[i:])
            if (i, d) in memo:
                return memo[(i, d)]
            ans, cur = 9999999999, 0
            for j in range(i, len(jD)): #遍历S(D_1)
                cur = max(cur, jD[j])
                x = dp(memo, jD, j + 1, d - 1)#核心代码 md(D_1^{rest}, d-1)
                if x != -1: 
                    ans = min(ans, cur + x)
            memo[(i, d)] = ans
            return ans
        return dp(memo, jD, 0, d)
```

