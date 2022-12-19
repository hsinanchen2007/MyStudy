#### 方法一：“量子”猪

**分析：每一只猪有多少种状态**

如果 `minutesToTest / minutesToDie = 0`，那么每一只猪只有一种状态，即存活。

如果 `minutesToTest / minutesToDie = 1`，那么每一只猪有两种状态，存活或者死亡。

进一步而言，如果 `minutesToTest / minutesToDie = 2`，那么每一只猪有三种状态，存活、在第一次测试后死亡、在第二次测试后死亡。

![bla](https://pic.leetcode-cn.com/Figures/458/pigs.png)

因此每一只猪的状态数量为 `states = minutesToTest / minutesToDie + 1`。
        
**分析：`x` 只 `2` 状态的猪最多可以测试多少个水桶**

显然，`1` 只猪可以测试 `1` 个水桶：让它喝下桶 `1` 的水，如果存活说明 `2` 号桶是毒药，如果死亡说明 `1` 号桶是毒药。

![bla](https://pic.leetcode-cn.com/Figures/458/pigs_bucket.png)

同理，`2` 只猪可以测试 `4` 个水桶。

![bla](https://pic.leetcode-cn.com/Figures/458/2_pigs.png)

![bla](https://pic.leetcode-cn.com/Figures/458/2_pigs_results.png)

更一般地，`x` 只猪可以测试 $2^x$ 个水桶。

**分析：`x` 只 `s` 状态的猪最多可以测试多少个水桶**

可以推导出，答案是 $s^x$，下图给出了 `x = 1`，`s = 3` 的例子。

![bla](https://pic.leetcode-cn.com/Figures/458/1_pig_2_tries.png)

![bla](https://pic.leetcode-cn.com/Figures/458/1_pig_results.png)

因此我们需要找到最小的 `x`，使得 $\textrm{states}^x \ge \textrm{buckets}$，其中 `states = minutesToTest / minutesToDie + 1` 表示每只猪的状态数。因此答案为$x \ge \log_{\textrm{states}}{\textrm{buckets}}$。根据换底公式，我们可以得到：

$$
x \ge \frac{\log \textrm{buckets}}{\log \textrm{states}}
$$

```C++ [sol1]
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int states = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(states));
    }
};
```

```Java [sol1]
class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int states = minutesToTest / minutesToDie + 1;
        return (int) Math.ceil(Math.log(buckets) / Math.log(states));
    }
}
```

```Python [sol1]
class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        states = minutesToTest // minutesToDie + 1
        return math.ceil(math.log(buckets) / math.log(states))
```

**复杂度分析**

* 时间复杂度：$O(1)$。

* 空间复杂度：$O(1)$。