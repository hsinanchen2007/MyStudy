#### 方法：动态规划

**思路**

首先，容易发现我们能将乘法块与除法块分开考虑，其中每一个块都应该是 `x` 的次幂，例如： `x / x`、`x`、`x * x`、`x * x * x`、`x * x * x * x` 等等。（这里我们没有理由去考虑形如 `x * x / x` 的表达式，因为一定有更优的方式达到相同的效果）

让我们定义一个块的花费为表示它所需要使用的运算符（包括块的前导加号或减号）的数量。举一个例子，我们可以把 `x * x + x + x / x` 想象成 `(+ x * x) (+ x) (+ x / x)` 。那么它的所有块花费之和就是 `2 + 1 + 2`，再为最前面无用的前导符号减 `1`，所以最终花费为 `4`。

对于有意义的块 $x^e$，可以计算出它的价值就是 $e$（当 $e = 0$ 的时候除外，其价值为 $2$）。我们的目的就是计算所有块的价值之和再减一。

现在，我们就把原问题简化为：我们知道 $x^e$ 与 $-x^e$ 的价值，并且我们希望用最少的价值表示目标值。

注意到在模 $x$ 的意义下，能改变目标值的块只有 $x^0$。定义 $r_1 = \text{target} \pmod x$，为了能够构造出目标值 $target$，我们要么从目标值中减去 $r_1$ 个 $x^0$，要么加上 $x-r_1$ 个 $x^0$。在此操作之后，我们会得到一个新的目标 $\text{target}_2$，并且它能被 $x$ 整除。

然后，在模 $x^2$ 的意义下，能改变目标值的块只有 $x^1$ 与 $x^0$了。同时，新的目标值 $target2$ 能被 $x$ 整除，所以我们没有必要使用 $x^0$，因为我们至少使用 $x$ 个 $x^0$ 才能达到 $1$ 个 $x^1$ 的效果，这是肯定不优的。

类似的方式，我们可以再进行一次。令 $r_2 = \text{target}_2 \pmod {x^2}$，我们要么减去 $r_2 / x$ 个 $x^1$ ，要么加上 $x - r_2 / x$ 个 $x^1$，经过此步骤之后，我们可以得到一个能被 $x^2$ 整除的 $\text{target}_3$，以此类推。

举一个具体的例子，假设 `x = 5` 且 `target = 123`。 起初，目标值为 `123` ，我们要么加 `2` ，要么减 `3`，此步骤会让目标值变化为 `120` 或 `125`。如果现在目标值为 `120`，我们可以加 `5` 或减 `20`，让目标变为 `100` 或 `125`。如果目标值为 `100`，那么我们可以加 `25` 或减 `100`，让目标值变为 `125` 或 `0`。如果目标值为 `125`，我们减 `125` 就可以完成构造。

**算法**

我们可以使用动态规划自顶向下地计算 `dp(i, target)`。这里的 `i` 表示我们正在考虑使用 $x^i$ 来改变目标值，使原本的 `target` 将会变成一个新的且能被 $x^i$ 整除的目标值。

到这里，整个递归过程就非常的明显了：$r = \text{target} \pmod x$，我们要么减去 $r$ 个块，要么增加 $(x-r)$ 个块。边界情况很容易就能推出来，具体细节可以看代码实现。

```java [smjaHx5K-Java]
class Solution {
    Map<String, Integer> memo;
    int x;
    public int leastOpsExpressTarget(int x, int target) {
        memo = new HashMap();
        this.x = x;
        return dp(0, target) - 1;
    }

    public int dp(int i, int target) {
        String code = "" + i + "#" + target;
        if (memo.containsKey(code))
            return memo.get(code);

        int ans;
        if (target == 0) {
            ans = 0;
        } else if (target == 1) {
            ans = cost(i);
        } else if (i >= 39) {
            ans = target + 1;
        } else {
            int t = target / x;
            int r = target % x;
            ans = Math.min(r * cost(i) + dp(i+1, t),
                           (x-r) * cost(i) + dp(i+1, t+1));
        }

        memo.put(code, ans);
        return ans;
    }

    public int cost(int x) {
        return x > 0 ? x : 2;
    }
}
```
```python [smjaHx5K-Python]
from functools import lru_cache

class Solution(object):
    def leastOpsExpressTarget(self, x, target):
        cost = list(range(40))
        cost[0] = 2

        @lru_cache(None)
        def dp(i, targ):
            if targ == 0: return 0
            if targ == 1: return cost[i]
            if i >= 39: return float('inf')

            t, r = divmod(targ, x)
            return min(r * cost[i] + dp(i+1, t),
                       (x-r) * cost[i] + dp(i+1, t+1))

        return dp(0, target) - 1
```


**复杂度分析**

* 时间复杂度：$O(\log_{x} \text{target})$。可以证明对于目标值在 `x进制` 下的每一位，我们最多只会访问两种有意义的状态。

* 空间复杂度：$O(\log \text{target})​$。
  

  
