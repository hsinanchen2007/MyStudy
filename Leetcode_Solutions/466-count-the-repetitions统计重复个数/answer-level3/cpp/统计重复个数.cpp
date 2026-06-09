#### 方法一：找出循环节

由于题目中的 `n1` 和 `n2` 都很大，因此我们无法真正把 `S1 = [s1, n1]` 和 `S2 = [s2, n2]` 都显式地表示出来。由于这两个字符串都是不断循环的，因此我们可以考虑找出 `s2` 在 `S1` 中出现的规律，如果我们找到了循环节，那么我们就可以很快算出 `s2` 在 `S1` 中出现了多少次了。

下图中给出了我们找出循环节的方式：

![Count the repitition](https://pic.leetcode-cn.com/Figures/466/count_the_repititions.png){:width="600px"}
{:align="center"}

当我们找出循环节后，我们计算出循环节的长度以及在循环节出现前的长度，这样就可以在 $O(1)$ 的时间内，通过减法和出发计算出 `s2` 在 `S1` 中出现的次数了。

然而循环节一定会出现吗？答案是肯定的，根据鸽巢原理，我们最多只要找过 `|s2| + 1` 个 `s1`，就一定会出现循环节。我们的算法如下所述：

- 初始化 `count = 0` 以及 `index = 0`；

- 初始化两个数组 `indexr` 和 `countr`，长度均为 `|s2| + 1`；

- 将 `i` 从 `0` 到 `n1 - 1` 循环；

    - 将 `j` 从 `0` 到 `|s1| - 1` 循环；

        - 如果 `s1[j] == s2[index]`，那么增加 `index`；

        - 如果 `index == |s2|`，那么将 `index` 置为 `0` 并增加 `count`。
    
    - 将 `countr[i]` 置为 `count`，`indexr[i]` 置为 `index`;

    - 将 `k` 从 `0` 到 `i - 1` 循环：

        - 如果我们找到循环节，即 `index == indexr[k]`，那么就进行如下计算：

            - $\text{prev\_count} = \text{countr}[k]$

            - $\text{pattern\_count} = (\text{countr}[i] - \text{countr}[k]) * \frac{n1 - 1 - k}{i - k}$

            - $\text{remain\_count} = \text{countr}\left[k + \left(n1 - 1 - k\right) \% \left(i - k \right)\right]$
        
        - 对上述三个值求和并除以 `n2` 即可得到答案；

        - 如果我们没有找到循环节，那么答案为 `countr[n1 - 1] / n2`。

```C++ [sol1]
int getMaxRepetitions(string s1, int n1, string s2, int n2)
{
    if (n1 == 0)
        return 0;
    int indexr[s2.size() + 1] = { 0 }; // index at start of each s1 block
    int countr[s2.size() + 1] = { 0 }; // count of repititions till the present s1 block
    int index = 0, count = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < s1.size(); j++) {
            if (s1[j] == s2[index])
                ++index;
            if (index == s2.size()) {
                index = 0;
                ++count;
            }
        }
        countr[i] = count;
        indexr[i] = index;
        for (int k = 0; k < i; k++) {
            if (indexr[k] == index) {
                int prev_count = countr[k];
                int pattern_count = (countr[i] - countr[k]) * (n1 - 1 - k) / (i - k);
                int remain_count = countr[k + (n1 - 1 - k) % (i - k)] - countr[k];
                return (prev_count + pattern_count + remain_count) / n2;
            }
        }
    }
    return countr[n1 - 1] / n2;
}
```

**复杂度分析**

* 时间复杂度：$O(|s1|*|s2|)$。

* 空间复杂度：$O(|s2|)$。