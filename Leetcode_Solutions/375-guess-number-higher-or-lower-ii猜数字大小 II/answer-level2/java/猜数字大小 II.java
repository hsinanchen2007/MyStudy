### 概要

给一个数字 $n$ ，我们要用最优策略在 $(1, n)$ 范围内考虑猜中数字的最坏情况。每次错误的尝试 $i$ 都会导致总开销增加 $i$ 。

比方说：
```
n=5
1 2 3 4 5
```
假设答案是 5 ，如果我们一开始猜 3 ，那么我们下一次肯定猜 4 ，最终总代价为 $4+3=7$ 。

假设答案是 3 或者 1, ，我们一开始猜 4 ，下一次猜 2 ，那么总代价为 $4+2=6$ ，这是最小总代价。

```
n=8
1 2 3 4 5 6 7 8
```
这种情况下我们先猜 5 然后猜 7 。总开销为 $5+7=12$ 。
如果我们先猜 4 。总开销为 $4+5+7=16$ 。

### 解法

#### 方法 1：暴力

首先，我们需要意识到我们在范围 $(1, n)$ 中猜数字的时候，需要考虑最坏情况下的代价。也就是说要算每次都猜错的情况下的总体最大开销。

在暴力算法中，我们首先在 $(1, n)$ 中任意挑选一个数字，假设它是个错误的猜测（最坏情况），我们需要用最小代价去猜到需要的数字。那么在一次尝试以后，答案要么在我们猜的数字的左边要么在右边，为了考虑最坏情况，我们需要考虑两者的较大值。因此，如果我们选择 $i$ 作为第一次尝试，总体最小代价是：

$$
\mathrm{cost}(1, n)=i + \max\big(\mathrm{cost}(1,i-1), \mathrm{cost}(i+1,n)\big)
$$

对于左右两段，我们分别考虑在段内选择一个数，并重复上面的过程来求得最小开销。

使用如上方法，我们能求得从 $i$ 开始猜，猜到答案的最小代价。同样地，我们遍历 $(1, n)$ 中的所有数字并分别作为第一次尝试，求出每一个的代价，并输入最小值即为答案。

```Java []
public class Solution {
    public int calculate(int low, int high) {
        if (low >= high)
            return 0;
        int minres = Integer.MAX_VALUE;
        for (int i = low; i <= high; i++) {
            int res = i + Math.max(calculate(i + 1, high), calculate(low, i - 1));
            minres = Math.min(res, minres);
        }

        return minres;
    }
    public int getMoneyAmount(int n) {
        return calculate(1, n);
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n!)$ 。我们选择一个数作为第一次尝试，然后递归中再选一个数，这样重复 $n$ 次的时间代价为 $O(n!)$ 。
* 空间复杂度： $O(n)$ 。 $n$ 层递归的开销。


#### 方法 2：修改后的暴力

**算法**

在暴力解中，对于范围 $(i, j)$ 中的每一个数字，我们都需要分别考虑选为当前的第一个猜测的代价，然后再分别考虑左右两个区间内的代价。但一个重要的发现是如果我们从范围 $\big( i,\frac{i+j}{2} \big)$ 内选择数字作为第一次尝试，右边区间都比左边区间大，所以我们只需要从右边区间获取最大开销即可，因为它的开销肯定比左边区间的要大。为了减少这个开销，我们第一次尝试肯定从 $\big(\frac{i+j}{2}, j\big)$ 中进行选数。这样子，两个区间的开销会更接近且总体开销会更小。

所以，我们不需要从 $i$ 到 $j$ 遍历每个数字，只需要从 $\frac{i+j}{2}$ 到 $j$ 遍历，且找到暴力解的最小开销即可。

```Java []
public class Solution {
    public int calculate(int low, int high) {
        if (low >= high)
            return 0;
        int minres = Integer.MAX_VALUE;
        for (int i = (low + high) / 2; i <= high; i++) {
            int res = i + Math.max(calculate(i + 1, high), calculate(low, i - 1));
            minres = Math.min(res, minres);
        }
        return minres;
    }
    public int getMoneyAmount(int n) {
        return calculate(1, n);
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n!)$ 。我们选择一个数作为当前第一次尝试，然后在递归中重复这个过程，总时间开销为 $O(n!)$ 。
* 空间复杂度： $O(n)$ 。递归的深度为 $n$ 。


#### 方法 3： DP

**算法**

以 $i$ 为第一次尝试找到最小开销的过程可以被分解为找左右区间内最小开销的子问题。对于每个区间，我们重复问题拆分的过程，得到更多子问题，这启发我们可以用 DP 解决这个问题。

我们需要使用一个 $dp$ 矩阵，其中 $dp(i, j)$ 代表在 $(i, j)$ 中最坏情况下最小开销的代价。现在我们只需要考虑如何求出这个 $dp$ 数组。如果区间只剩下一个数 $k$ ，那么猜中的代价永远为 0 ，因为我们区间里只剩下一个数字，也就是说，所有的 $dp(k, k)$ 都初始化为 0 。然后，对于长度为 2 的区间，我们需要所有长度为 1 的区间的结果。由此我们可以看出，为了求出长度为 $len$ 区间的解，我们需要所有长度为 $len-1$ 的解。因此我们按照区间长度从短到长求出 $dp$ 数组。

现在，我们应该按照什么办法来求出 $dp$ 矩阵呢？对于每个 $dp(i, j)$ ，当前长度为 $len=j-i+1$ 。我们遵照方法 1 中俄办法，依次挑选每个数字作为第一次尝试的答案，可以求出最小开销：

$$
\mathrm{cost}(i, j)=\mathrm{pivot} + \max\big(\mathrm{cost}(i,\mathrm{pivot}-1), \mathrm{cost}(\mathrm{pivot}+1,n)\big)
$$

但是在计算开销的时候我们有一个便利之处，就是我们已经知道了小于 $len$ 长度 $dp$ 数组的所有答案。因此 dp 方程式变成了：

$$
\mathrm{dp}(i, j) = \min_{\mathrm{pivots}(i, j)} \big[ \mathrm{pivot} + \max \big( \mathrm{dp}(i,\mathrm{pivot}-1) , \mathrm{dp}(\mathrm{pivot}+1,n) \big) \big]
$$

其中 $\min_{\mathrm{pivots}(i, j)}$ 表示将 $(i, j)$ 中的每个数作为第一个尝试的数。

下面的动画更好地说明了 `n=5` 的情况：

<![image.png](https://pic.leetcode-cn.com/ab62c6f959a723cd1777251c7b8ec17b2207ca6852b2e2c8a3e6efadaac4810c-image.png),![image.png](https://pic.leetcode-cn.com/6101e774ede46ed6eca6e367ac0fffe402e18b56648b2abf19b25059ab23c848-image.png),![image.png](https://pic.leetcode-cn.com/6ac9d40d277ef35a9b001a1daeeeaf7f96556b2254c71c344f1193c92e490f05-image.png),![image.png](https://pic.leetcode-cn.com/f844f408b64eacdc56f3ccf0df2db172688665284ddce1ec755d9fb4230b3af2-image.png),![image.png](https://pic.leetcode-cn.com/a5eb81438976de13c1bb4c8fc4f36a1bfc9c6f7f12f1c7134cba81db914b4b69-image.png),![image.png](https://pic.leetcode-cn.com/6331c2db1c74a7322ae728b1ab769e1dbf92740bc989fe523673640a0774f98a-image.png),![image.png](https://pic.leetcode-cn.com/7a923085dd5815df2516c208b2e1627586c4f93d663207758b233f05a3a47599-image.png),![image.png](https://pic.leetcode-cn.com/94a7efecca2d88d3cc755daddebe7e3e06def87e22fa6a99cd59f52c9527c95d-image.png),![image.png](https://pic.leetcode-cn.com/f51b41118bed4c15734d75a32e34155e7141ac8afa84398730da221b487c6629-image.png),![image.png](https://pic.leetcode-cn.com/38a8868b9f6dc0b1698192d511e8fcddb18771d33100dd3465f39e9afd2b1292-image.png),![image.png](https://pic.leetcode-cn.com/461abb46f9bd74da88917364bc99c9367fde5652568822f3921fdae1419e4ea1-image.png),![image.png](https://pic.leetcode-cn.com/4f46f5067737190a67422064da61aebd676388d97744158b0b14fd3d12fe46dd-image.png),![image.png](https://pic.leetcode-cn.com/19308c0c6876e616e90e3731ae869f63b3f614875df3353f436da50bb587c805-image.png),![image.png](https://pic.leetcode-cn.com/8c68b4742a33c9e357bc52e70b6e7de7689e218da9c07d43100e505e673a3cf6-image.png),![image.png](https://pic.leetcode-cn.com/7d14537b72c09db6c9cfef47e66eed1acdb4714bf3205553525f5248fd9c8ecd-image.png),![image.png](https://pic.leetcode-cn.com/080612d263a8db3a4b289bbb7edc96beaaeaa736d9afd872c1e6f88e56d3df5f-image.png),![image.png](https://pic.leetcode-cn.com/fb86565f5ef3f7f7f4b12dda329de17215613b1775f113f1f3f2911341820ad0-image.png)>

```Java []
public class Solution {
    public int getMoneyAmount(int n) {
        int[][] dp = new int[n + 1][n + 1];
        for (int len = 2; len <= n; len++) {
            for (int start = 1; start <= n - len + 1; start++) {
                int minres = Integer.MAX_VALUE;
                for (int piv = start; piv < start + len - 1; piv++) {
                    int res = piv + Math.max(dp[start][piv - 1], dp[piv + 1][start + len - 1]);
                    minres = Math.min(res, minres);
                }
                dp[start][start + len - 1] = minres;
            }
        }
        return dp[1][n];
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n^3)$ 。我们遍历 $dp$ 数组一遍需要 $O(n^2)$ 的时间开销。对于数组中每个元素，我们最多需要遍历 $n$ 个数字。

* 空间复杂度： $O(n^2)$ 。需要创建 $n^2$ 空间的 $dp$数组。


#### 方法 4：优化的 DP

**算法**

在上一个方法中，我们尝试使用 $(i, j)$ 中的每一个数作为第一个选的数。但由于方法 2 中提到的原因，我们只需要从 $\big(i+(len-1)/2,j\big)$ 中选第一个数就可以了，其中 $len$ 是当前区间的长度。因此转移方程式为：

$$
\mathrm{dp}(i, j)=\min_{\mathrm{pivots}\big(i+\frac{len-1}{2}, j\big)}\big[\mathrm{pivot} + \max\big(\mathrm{dp}(i,\mathrm{pivot}-1), \mathrm{dp}(\mathrm{pivot}+1,n)\big)\big]
$$

通过这种方法我们可以在一定程度上优化方法 3 。

```Java []
public class Solution {
    public int getMoneyAmount(int n) {
        int[][] dp = new int[n + 1][n + 1];

        for (int len = 2; len <= n; len++) {
            for (int start = 1; start <= n - len + 1; start++) {
                int minres = Integer.MAX_VALUE;
                for (int piv = start + (len - 1) / 2; piv < start + len - 1; piv++) {
                    int res = piv + Math.max(dp[start][piv - 1], dp[piv + 1][start + len - 1]);
                    minres = Math.min(res, minres);
                }
                dp[start][start + len - 1] = minres;
            }

        }
        return dp[1][n];
    }
}
```

**复杂度分析**

* 时间复杂度： $O(n^3)$ 。我们遍历整个 $dp$ 矩阵一次需要 $O(n^2)$ 的时间。对于数组中每个元素，我们最多需要遍历 $\frac{n}{2}$ 个元素。

* 空间复杂度： $O(n^2)$ 。 $dp$ 数组的空间开销为 $n^2$ 。
