> 原文发布于我的博客： [leetcode-cn 题解 面试题57 - II. 和为s的连续正数序列](https://blog.by24.cn/archives/leetcode-he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof.html)

## 解法1

#### 解法1思路

第一眼看到题目，直觉上就是数学题，毕竟等差数列是可以用公式求和的。

我们现在设：

- 目标数字 target 为 **T**
- 单条组合的首项数字为 **S**
- 单条组合的数字个数为 **N**


![image.png](https://pic.leetcode-cn.com/1c489e724e130aeb9875620bc5ba6bad6bffa9c868309c24d0b9f4513ec768de-image.png)


那么根据等差数列求和公式：
$$
数列和 = \cfrac{(首项 + 末项) \times 项数}{2}
$$
可得：
$$
T = \cfrac{(S + ( S + N - 1)) \times N}{2}\\
$$
合并一下可得:
$$
(2S + N - 1) \times N = 2T~\\~\\2SN + N^2 - N = 2T~\\ ~\\N^2 + 2SN + (- N - 2T) = 0
$$
看起来我们把这个式子变的很像一个一元二次方程组了，但是还有很多变量需要想办法替换为常量。



此时可以想一下，如果我们希望 N 尽可能大，也就是整个数列的长度需要尽可能的长，为了达到这个目的，就需要让 S 尽可能的趋近于 1 才行。

也就是说，S = 1 的时候，N 才可能取到最大值，那么我们不妨直接将 S = 1带入公式，算算 N_MAX：
$$
N^2 + 2N + (-N - 2T) = 0\\N^2 + N + (-2T) = 0
$$
需要注意的是，这里的 T 是常量，做题的时候会输入的，不要当变量处理了。

既然是一元二次方程，那就直接套公式求解吧：
$$
(\ a = 1\quad b=1 \quad c= -2T \ )\\N^2 + N + (- 2T) = 0 \\~\\(\ \Delta =\mathop{{b}}\nolimits^{{2}}-4ac\ )\\\Delta = \mathop{{1}}\nolimits^{{2}}-4\times1\times(-2T)\\\Delta = 1 + 8T~\\~\\(\ \mathop{{N}}\nolimits_{{1,2}}=\frac{{-b \pm \sqrt{{\mathop{{b}}\nolimits^{{2}}-4ac}}}}{{2a}}\ )\\\mathop{{N}}\nolimits_{{1,2}}=\frac{{-1 \pm \sqrt{{1+8T}}}}{{2}}\\
$$
算到这一步的时候需要注意了，此处我们并不需要求负数解，所以 $\Delta$ 前面的 $\pm$ 其实只需要保留 $+$ 号就够了，也就是：
$$
\mathop{{N}}=\frac{{\sqrt{{1+8T}}}}{{2}} - \frac{1}{2}
$$
算出了 N_MAX ，接下来就好办了，还是之前的等差数列公式，只是现在 S 变成了未知数，N 变成了常量：
$$
2SN + N^2 - N = 2T\\2SN = 2T - N^2 + N\\~\\S = \cfrac{2T - N^2 + N}{2N}
$$
这样 S 也就算出来了，只需要从 S 开始，数 N 个数，一个合格的数列就算出来了。

接下来只需要将 N 从 N_MAX 到 2 进行遍历，算出每一个对应的 S 就可以了。



诶等等？好像我们还没有判断是否存在相应的数列，比如 `T = 15, N = 4` 的时候，就不存在相应的解啊？

关于这个问题，不妨将上面 T, N 带入公式，计算一下 S ，就会发现，只有 S 为整数的时候，才存在解，答案自然就出来了。

#### 解法1代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        // 计算最多有多少位
        int n_max = (int) (Math.sqrt( 1.0 + 8 * target) / 2 - 0.5);
        int[][] ans = new int[n_max - 1][];
        int ans_num = 0;

        while (n_max > 1){
            double start = (2 * target - n_max * n_max + n_max) / (2.0 * n_max);
            if (Math.round(start) == start){
                ans[ans_num] = new int[n_max];
                for (int i = 0; i < n_max; i++)
                    ans[ans_num][i] = (int) (start + i);
                ans_num += 1;
            }
            n_max -= 1;
        }

        return Arrays.copyOfRange(ans, 0, ans_num);
    }
}

```

代码中看起来还存在可以优化的地方，并没有达到双百


![image.png](https://pic.leetcode-cn.com/1ce62a910b4b5f706b7ec00434e2b3d2609a8307c43da49076b3a5885a33fcfb-image.png)


## 解法2

#### 解法2思路

上面的解法 1 ，虽然看起来简单，但是毕竟不够快，那么接下来就来个更简单的思路。

我们取 **15** 这个数字作为示例，取其中两个解画个示意图：

![image.png](https://pic.leetcode-cn.com/c51de7eafb29e84c94b1611553949a082d9be117fb4c4c3b20516ea14a220442-image.png)


这个很简单的示意图，表达了一个简单的意思：

- `7 + 8` 可以写做 `7 * 2 + 1`
- `4 + 5 + 6` 可以写做 `4 * 3 + 1 + 2`

看起来好像没什么意思，那我们再把其它解也列出来看一看：

![image.png](https://pic.leetcode-cn.com/4cb8d4666f6cbbb31c6c8f4bcb9ca3fd5b1b1e5a74656fa51adfa0e248d50b5d-image.png)


诶怎么有个红色的？因为 15 并不存在被分解为连续 4 个整数的解，自然那里算不出合适的整数。

接下来让我们继续变化一下这组等式：

![image.png](https://pic.leetcode-cn.com/6e68780677810a47e9c0d543e3da9ddd6109d3ca972efbe8d90d025b72c41b7e-image.png)


这下就有意思了，看看右半边，全都是常数，而且每次都递减了一个数，而左侧的 S ，可以简单的通过除法计算出来，这个结构用来跑遍历实在是太方便了。


我们只需要先用 `15 - 1`，看看是否能被 2 整除，能的话，就存在 2 个数字的解。

再用 `15 - 1 - 2` ，看看结果是否能被 3 整除，又能算出是否有 3 个数字的解......

以此类推，直到 15 减不动了，也就意味着所有已知的结果都被算出来了。



这个解法思路比上面的方程法虽然绕了个小弯，但是却非常清晰，非常适合代码实现。

#### 解法2代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> res = new ArrayList<>();
        for (int i = 2; target > i; i++) {
            if ((target -= i - 1) % i == 0) {
                int[] a = new int[i];
                for (int j = 0; j < i; j++)
                    a[j] = target / i + j;
                res.add(0, a);
            }
        }
        return res.toArray(new int[0][]);
    }
}
```

这个解法不但简单，因为不存在开方平方之类的计算，耗时还更短，拿下双百


![image.png](https://pic.leetcode-cn.com/fd7909cd17b0d9a4b2b6f6da5a192c298d688a9b0abc25611c2898bacebe8695-image.png)




## 相关题目

其实 leetcode 上有另一道题和本题几乎一模一样，可以顺手一起做掉：

[829. 连续整数求和](https://leetcode-cn.com/problems/consecutive-numbers-sum/) ：https://leetcode-cn.com/problems/consecutive-numbers-sum/