其实第 4 题似乎是一道数学归纳法题 hh

## 迭代公式

譬如说，若订单数量 $n$ 所对应的序列数目定义为 $p(n)$；那么迭代公式是 (感谢 [@jartus](https://leetcode-cn.com/problems/count-all-valid-pickup-and-delivery-options/solution/shu-xue-gui-na-fa-qiu-jie-by-zhu-zhen-yu-ajz34/252615) 指正)

$$
p(n) = p(n - 1) \times (C_{2n-1}^2 + 2 n - 1) = p(n - 1) \times \left( (2 n - 1) n \right)
$$

迭代初始条件可以是 $p(1) = 1$，也可以是 $p(0) = 1$。

简单讨论上述公式的来源。那么我们现在考虑 $n = 4$ 的情况，即 $p(n) = 2520$。我们现在要将包裹 4 插入序列的队列中，有下述两种插入方法，其中一例可以是：
```
 O O O O O O
|     |
```
即第 4 个包裹的分发是两个分别的过程，相当于在 $(2 \times 3 + 1) = (2 \times 4 - 1) = 7$ 个插槽内插两条，因此这种插入方法总共有 $C_7^2 = 21$ 种可能性。再辅以原先 1-3 包裹的各种可能排序，这种情况对 $p(4)$ 的贡献是 $p(3) \times C_{2 \times 4 - 1}^2 = 90 \times 21 = 1890$。

另一例可以是：
```
  O  O  O  O  O  O
      ||
```
即第 4 个包裹的分发在一起，相当于在 $7$ 个插槽内插一条，因此插入方法有 $C_7^1 = 7$ 种可能性。因此，该情况对 $p(4)$ 的贡献是 $p(3) \times 7 = 90 \times 7 = 630$。

最后我们就可以得到 $p(4) = 1890 + 630 = 2520$ 种情况。可以验证，利用最初提到的迭代公式，确实能得到 $p(4) = p(3) \times (7 \times 4) = 2520$。对于其它的情况就可以类推。

## 关于大数同余

由于结果数值非常大，因此需要进行同余计算。

首先，我们在中间过程中尽量使用 `long long` 或者其它长整型，避免 10^9 量级的数与 10^2 量级的乘法导致短整型溢出。

其次，我们利用下述推论。若我们令 $a = k \times b + t$，其中 $0 \leqslant t < b$，$0 \leqslant k$ 且所有数均为非负数，即 `(a % b) = t`；那么

$$
a_1 a_2 = (k_1 k_2 b + k_1 t_2 + k_2 t_1) \times b + t_1 t_2
$$

即 `(a1 * a2) % b = (t_1 * t_2) % b`，或者说是乘法的模与余数积的模相等。

下述代码的函数 `mult_mod` 就是输入 `a1, a2`，返回当 `b = 10^9 + 7` 下的乘法后的模长。

## 代码

```c++
class Solution {
public:
    int countOrders(int n) {
        auto mult_mod = [](long long a1, long long a2) { return (a1 * a2) % 1000000007; };
        long long p = 1;
        for (int i = 1; i <= n; ++i)
            p = mult_mod(p, (2 * i - 1) * i);
        return int(p);
    }
};
```
