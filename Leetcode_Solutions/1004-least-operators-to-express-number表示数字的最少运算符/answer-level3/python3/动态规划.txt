## 思路:

**动态规划**

首先，这个问题一定有解，大不了我们一直用`x/x = 1`加到目标值。

其次，因为要最少运算符，所以尽量使用乘法，快速增长到目标值附近。

最后，到目标值附近，有三种可能（假如通过乘法到底目标值附近的值为`cur`）：

1. `cur  =  target`，这种情况直接输出即可；
2. `cur  >  target`，比如`cur  =  4，target  =  3, x  =  2`，这时候需要使用减法(比如`4 - 2/2 `)，只需找到能求得`cur - target`的最小运算符是什么即可；
3. `cur < target`，比如`cur  =  3, target  =  7, x  =  3`，这时候需要使用加法，只需找到`target - cur`最小运算符是什么即可。

但是，当`target < x`时候，比如`target = 2, x = 3`，我们有两种方法到达目标值，一种是`3/3 + 3/3`；一种是`3- 3/3`，换句话说，一种全是用`1`相加，一种先用`x`再减`1`，判断谁用操作符最少。

所以，我们可以用带记忆法递归求的解，代码如下：

## 代码:

```python
class Solution:
    def leastOpsExpressTarget(self, x: int, target: int) -> int:
        from functools import lru_cache

        @lru_cache(None)
        def dfs(cur):
            # 当cur < x, 比如 cur = 2, x = 3, 需要判断使用 3/3 + 3/3 和 3 - 3/3,哪个用运算符最少
            if cur < x:
                return min(2 * cur - 1, (x - cur) * 2)
            if cur == 0:
                return 0
            # 到cur 需要几个x相乘,
            p = int(math.log(cur, x))
            sums = x ** p
            # cur < sums 的情况,就是要加
            ans = dfs(cur - sums) + p
            # sums > cur, 就是要减去多少才能到底目标值, 这个判断条件是有严格的数学证明的
            if sums * x - cur < cur:
                ans = min(ans, p + 1 + dfs(sums * x - cur))
            return ans

        return dfs(target)

```

