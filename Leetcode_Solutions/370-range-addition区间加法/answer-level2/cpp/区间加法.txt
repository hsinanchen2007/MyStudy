#### 方法 1：简单的暴力

**算法**

这个算法十分显然。对于每个更新操作，我们遍历要求的更新区间并把每个元素分别更新。

每个 `updates` 操作都是 3 个整数的三元组： $start, end$ （更新的开始结束下标）和 $val$ （这个范围内每个元素需要增加的值）。

```C++ []
vector<int> getModifiedArray(int length, vector<vector<int> > updates)
{
    vector<int> result(length, 0);

    for (auto& tuple : updates) {
        int start = tuple[0], end = tuple[1], val = tuple[2];

        for (int i = start; i <= end; i++) {
            result[i] += val;
        }
    }

    return result;
}
```

**复杂度分析**

* 时间复杂度： $O(n \cdot k)$ ，其中 $k$ 是更新操作的数目， $n$ 是数组的长度。最坏情况下，每个更新操作都会把所有 $n$ 个元素遍历一遍。

* 空间复杂度： $O(1)$ 。不需要额外空间。


#### 方法 2： 区间求和

**想法**

* 由于只有一次对所有数的查询，且发生在所有更新操作之后的最后，并且每次更新操作都是互不相关的。

* 累积和以及部分和操作只对操作区间内的数字有影响，对其他数字没有影响。

**算法**

这个算法利用以上想法，只在操作区间的边界上存储变化的值（而不是整个区间都进行更新）。最终只需要对整个数组求一遍和。

以下两步就是具体过程：

1. 对每一个更新操作 $(start, end, val)$ ，我们用一个求和数组 $arr$ 来记录变化值，我们做 2 个操作：

    * 更新 $start$ ：

    $$
    arr_{start} = arr_{start} + val
    $$

    * 更新 $end$ 的下一个位置：

    $$
    arr_{end+1} = arr_{end+1} - val
    $$

2. 最终，求整个数组的前缀和（`0` 是一个基准位置）。

    $$
    arr_i = arr_i + arr_{i-1} \quad \forall \quad i \in [1, n)
    $$


```C++ []
vector<int> getModifiedArray(int length, vector<vector<int> > updates)
{
    vector<int> result(length, 0);

    for (auto& tuple : updates) {
        int start = tuple[0], end = tuple[1], val = tuple[2];

        result[start] += val;
        if (end < length - 1)
            result[end + 1] -= val;
    }

    // partial_sum applies the following operation (by default) for the parameters {x[0], x[n], y[0]}:
    // y[0] = x[0]
    // y[1] = y[0] + x[1]
    // y[2] = y[1] + x[2]
    // ...  ...  ...
    // y[n] = y[n-1] + x[n]

    partial_sum(result.begin(), result.end(), result.begin());

    return result;
}
```

**正式解释**

对每一个针对数组 $arr$ 的更新操作，目的都是更新结果：

$$
arr_i = arr_i + val \quad \forall \quad i \in [start, end]
$$

在最后的答案数组里，产生的效果是：

1. 每一个 $arr_i \; \forall \; i \ge start$ ，最终答案都增加了 $val$ 。
2. 每一个 $arr_j \; \forall \; j \gt end$ ，最终答案都增加了 $-val$ ，等价于减少 $+val$ 。

产生的结果影响是：

$$
\begin{aligned}
arr_i &= arr_i + val  \quad && \forall \quad i \in [start, end] \\
arr_j &= arr_j + val - val = arr_j  \quad && \forall \quad i \in (end, length)
\end{aligned}
$$

这与我们最终想要的结果一致。我们可以看出来因为后面的元素增加了 $-val$ ，所以某个范围内的更新不会对该范围后面的元素造成影响。

值得注意的是对同一个数组的多个更新操作用这个方法同样有效，这是因为这两个特殊特殊的二元操作（也就是加法和减法）满足：

* 在整个整数域上是 *封闭* 的。比方除法在整数域上就不是封闭的。

* *互补* 。比方乘法和除法就不总是互补的，因为在除以整数的时候可能会丢失精度。

**复杂度分析**

* 时间复杂度： $O(n + k)$ 。 $k$ 个更新操作中的每一个都在常数时间内可以完成。累积时间复杂度总是为 $O(n)$ 。

* 空间复杂度： $O(1)$ 。不需要使用额外的空间。


### 更多思考

此问题的一个拓展是如何将这样的更新操作应用在一个初始元素 *不* 是一样的数组里。

这种情况下，第二种方法需要额外的 $O(n)$ 的空间来保存初始的值。

另一种不需要额外空间的方法，但需要对数组做一次额外的线性遍历，这个想法跟上面部分和的想法正好相反，比方说将数组 $[2, 3, 10, 5]$ 转变成 $[2, 1, 7, -5]$ 作为 $arr$ 数组的初始值，然后后面操作照常。