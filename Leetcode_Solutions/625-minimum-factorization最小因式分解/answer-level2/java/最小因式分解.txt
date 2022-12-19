#### 方法一：枚举 [超出时间限制]

最简单的做法是枚举所有 `32` 位有符号正整数。我们从 `1` 开始枚举，对于每个数，我们依次判断它的所有数位相乘是否等于 `a`。如果没有找到符合条件的数，我们就返回 `0`。

```Java [sol1]
public class Solution {
    public int smallestFactorization(int a) {
        for (int i = 1; i < 999999999; i++) {
            long mul = 1, t = i;
            while (t != 0) {
                mul *= t % 10;
                t /= 10;
            }
            if (mul == a && mul <= Integer.MAX_VALUE)
                return i;
        }
        return 0;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(\text{INT\_MAX})$，其中 $\text{INT\_MAX}$ 是最大的 `32` 位有符号正整数。当我们给出的 `a` 是一个大质数时，显然不会有符合条件的数，因此这个算法会遍历所有的数然后返回 `0`。

* 空间复杂度：$O(1)$。

#### 方法二：深度优先搜索

我们可以对方法一中的枚举进行优化，每次枚举数的某一位，通过深度优先搜索的方式找出答案。

我们首先可以挖掘出答案 `b` 的一些性质。

- 如果 `a` 大于 `1`，那么 `b` 中不会包含数字 `1`；
- `b` 中的数字从低位向高位看是单调不增的。例如 `2833` 一定不可能是答案，因为将这四个数字排成从低位到高位单调不增的 `2338` 比 `2833` 更小。

因此，我们可以从最低位数字（个位数字）开始枚举答案，并且每一位数字的取值下界为它右侧的数字 `2`，上界为它右侧的数字（如果右侧没有数字，则上界为 `9`），优先枚举大的数字。如果当前枚举了 `k` 位数字，并且这 `k` 个数字的乘积大于 `a`，我们就需要进行回溯；如果等于 `a`，那么我们就找到了答案，并且直接跳出搜索，因为如果优先枚举大的数字，第一个找到的答案一定是最小的；如果小于 `a`，那我们枚举第 `k + 1` 位并继续进行深度优先搜索。

<![1000](https://pic.leetcode-cn.com/Figures/625/625_Minimum_FactorizationSlide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/625/625_Minimum_FactorizationSlide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/625/625_Minimum_FactorizationSlide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/625/625_Minimum_FactorizationSlide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/625/625_Minimum_FactorizationSlide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/625/625_Minimum_FactorizationSlide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/625/625_Minimum_FactorizationSlide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/625/625_Minimum_FactorizationSlide8.PNG),![1000](https://pic.leetcode-cn.com/Figures/625/625_Minimum_FactorizationSlide9.PNG),![1000](https://pic.leetcode-cn.com/Figures/625/625_Minimum_FactorizationSlide10.PNG),![1000](https://pic.leetcode-cn.com/Figures/625/625_Minimum_FactorizationSlide11.PNG)>

这种方法的时间复杂度仍然很高，虽然不是最优的方法，但可以在时间限制内通过本题。

```Java [sol2]
public class Solution {
    long ans;
    public int smallestFactorization(int a) {
        if(a < 2)
            return a;
        int[] dig=new int[]{9, 8, 7, 6, 5, 4, 3, 2};
        if (search(dig, 0, a, 1, "") && ans <= Integer.MAX_VALUE)
            return (int)ans;
        return 0;
    }
    public boolean search(int[] dig, int i, int a, long mul, String res) {
        if (mul > a || i == dig.length )
            return false;
        if (mul == a) {
            ans = Long.parseLong(res);
            return true;
        }
        return search(dig, i, a, mul * dig[i], dig[i] + res) || search(dig, i + 1, a, mul, res);
    }
}
```

**复杂度分析**

* 时间复杂度：指数级别，无法用大 $O$ 表示法直接给出。

* 空间复杂度：$O(\log a)$，在最坏情况下，当每一个数位都是 `2` 时，深度优先搜索需要的栈空间为 $O(\log a)$。

#### 方法三：因式分解

从方法二中的搜索策略中我们可以发现，从低位开始枚举时，我们尽量把这一个数位上的数字放得越大越好。因此我们可以想到一种贪心的策略：我们还是从最低位开始枚举，并一直放 `9` 直到 `a` 不能被 `9` 整除，即 `a` 能表示成 `a = a0 * 9^t` 且 `t` 尽量大，那么我们从低位开始放 `t` 个 `9`，并将 `a` 置为 `a0`。接下来，我们一直放 `8` 直到 `a0` 不能被 `8` 整除，一直放 `7` 直到 `a0` 不能被 `7` 整除，以此类推。这种贪心方法和深度优先搜索的策略本质上是一样的，只不过直接找出了最终答案，避免了不必要的搜索。

```Java [sol3]
public class Solution {
    public int smallestFactorization(int a) {
        if (a < 2)
            return a;
        long res = 0, mul = 1;
        for (int i = 9; i >= 2; i--) {
            while (a % i == 0) {
                a /= i;
                res = mul * i + res;
                mul *= 10;
            }
        }
        return a < 2 && res <= Integer.MAX_VALUE ? (int)res : 0;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(\log a)$，将一个数进行因式分解后，它最多可以表示成 $O(\log a)$ 个数的乘积。

* 空间复杂度：$O(1)$。