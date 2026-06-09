>  ⚠️ **高复杂度提醒**
>
> 按下述思路解题的耗时尽管也不长 (16 ms)，复杂度计算 $O(n \log n)$、内存 $O(n)$，因为我们开了向量对数字进行了大小排序。
> 但还请参考官方题解或 [c++ 去掉最小值 8ms](https://leetcode-cn.com/problems/largest-multiple-of-three/solution/c-qu-diao-zui-xiao-zhi-8ms-by-yusenzhang_chatc/) 的题解。
> 上述题解或许更简洁，且复杂度计算 $O(n)$。内存 $O(1)$，都更小。分类讨论过程类似但略有区别。

<br>
第 4 题的最大问题我觉得其实是分类讨论。

这道题的思路应该还蛮简单的，我们要取出所有 digits 中，数量最多且数值最大的子数组，使得该子数组的和模 3 余 0。

十进制数字之和能被 3 整除的数，本身也能被 3 整除，这算是一个需要利用到的技巧吧。文档最后会介绍其证明。

但是具体实现起来，就需要作一些分类讨论了。

## 例子：`[1, 2, 3, 4, 5, 6, 7]`

### 1. 对 `digits` 按模 3 余数分类

我们先以输入数组为 `[1, 2, 3, 4, 5, 6, 7]` 的情况为例；我出现的一次提交错误也跟这个情况有关。
答案应该是 `"765432"`，因为上述数组剔除 `1` 后的子数组和 $2+3+4+5+6+7 = 27$ 可以被 3 整除，而 `[7, 6, 5, 4, 3, 2]` 是值最大的子数组。

首先我们需要从 `digits` 的所有数字放入 `digits_map` 映射 (用 C++ 向量实现)。

- `digits_map[0]` 储存所有 `digits` 中出现过的模 3 余 0 的数 (`[3, 6]`)；
- `digits_map[1]` 模 3 余 1 (`[1, 4, 7]`)；
- `digits_map[2]` 模 3 数 2 (`[2, 5]`)。

### 2. 选择需要的数字

接下来我们将所有需要的数字放入 `digits_result` 中。这个数组基本上就是最终结果了。判断需要的数字需要经历一下过程：

1. 所有模 3 余 0 的数字我们都先留下来，即用 `digits_map[0]` 初始化需要数字的向量 `digits_result`；
    因此现在 `digits_result` 包含 `[3, 6]` (目前情况下数字顺序不重要)。
2. 我们先对模 3 余 1 和 2 的数字作排序，且从大到小。这是为了方便我们 pop_back 数字。因此现在
    `digits_map[1] = [7, 4, 1]`, `digits_map[2] = [5, 2]`。
3. 我们先记录模 3 余 1 和 2 的数字数量 (模 3 的余数) 为 `mod_1 = digits_map[1].size() % 3 = 3 % 3 = 0`, `mod_2 = 2 % 3 = 2`。
    对于这种情况，我们发现，如果我们只剔除 `digits_map[1]` 末尾的 1，剩下的数字全都放入 `digits_result` 就行。
    因此，现在我们作 pop_back，`digits_map[1] = [7, 4]`。
4. 最后，我们将所有剩下的 `digits_map` 的数放入 `digits_result` 中，得到
    `digits_result = [3, 6, 7, 4, 5, 2]`。

### 3. 输出结果

最后，我们再对 `digits_result` 从大到小排序，得到 `[7, 6, 5, 4, 3, 2]`，成为字符串输出。

## 补充说明

### 对*选择需要的数字*的分类讨论

1. 如果 `mod_1 = 0` 且 `mod_2 = 2`，有两种可能性：
    1. 如果像上述例子一样，那么将含模 3 余 1 数字 `digits_map[1] = [7, 4, 1]` 剔除一个最小的就行；
    2. 但如果输入的数组是 `[2, 2, 5, 5, 5]`，没有模 3 余 1 数字，那么我们只能将最小的两个模 3 余 2 数字 `[2, 2]` 剔除；
2. `mod_1 = 2` 且 `mod_2 = 0`，仿上；
3. 如果 `mod_2 - mod_1 = 1`，譬如输入数组为 `[2, 5, 1, 4, 4, 7]`，这时 `mod_2 = 2`, `mod_1 = 1`，那么我们只需要将模 3 余 2 数字 `digits_map[2] = [2, 5]` 剔除一个最小的一个就行；
4. 如果 `mod_1 - mod_2 = 1`，仿上；
5. 剩下的情况就是 `mod_1 = mod_2`，这种情况下我们可以保留所有数字。我们不需要做额外的工作。

### 对*输出结果*的补充

题干其实已经提示我们去避免了极端情况了。极端情况有

1. 如果 `digits_result` 什么也没有，那么就意味着没有任何子数组可以被 3 整除。
2. 如果从大到小排序后的 `digits_result` 首位是零，那么被 3 整除子数组就全是零了，结果自然也是零。

## 关于被 3 整除的数，其各位数之和也能被 3 整除的推论

对于任意正整数 $\forall b \in \mathbb{N}^{+}$，其在十进制下的位数 (digit) 若表示为 ${a_N \cdots a_2 a_1 a_0}$，即
$$
b = \sum_{n = 1}^N a_n 10^n \;,
$$
由于
$$
10^n \mod 3 = [9 \times 10^{(n - 1)} + 10^{(n - 1)}] \mod 3 = 10^{(n - 1)} \mod 3 = \cdots = 10 \mod 3 = 1
$$
因此，
$$
b \mod 3 = \sum_{n = 1}^N (a_n 10^n \mod 3) = \sum_{n = 1}^N (a_n \mod 3) = \left( \sum_{n = 1}^N a_n \right) \mod 3
$$
因此，$b$ 能被 3 整除，等价于其各位数之和也能被 3 整除。

PS. 这是我完成的第二道题。我上来就被前两道题卡死了 hh。第一道题，我以前没用过 ctime，我在想 C++ 要拿头做呀……
最后决定用 Python 的 datetime 了，不清楚这算不算作弊啊……
第二道题我用了错误的算法 AC 了，天真地以为只有一个根节点的树就是正确答案了 T.T 恐怕第二题标准答案是错的。

## 代码

```c++
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        // 1. 对 `digits` 按模 3 余数分类
        vector<vector<int>> digits_map(3, vector<int>{});
        for (int d : digits)
            digits_map[d % 3].push_back(d);
        // 2. 选择需要的数字
        vector<int> digits_result{ digits_map[0] };
        int mod_1 = digits_map[1].size() % 3, mod_2 = digits_map[2].size() % 3;
        sort(digits_map[1].begin(), digits_map[1].end(), greater<int>());
        sort(digits_map[2].begin(), digits_map[2].end(), greater<int>());      // 对*选择需要的数字*的分类讨论
        if (mod_2 - mod_1 == 2)                                                // situ. 1
            if (digits_map[1].size() > 0) digits_map[1].pop_back();            // situ. 1.1
            else { digits_map[2].pop_back(); digits_map[2].pop_back(); }       // situ. 1.2
        else if (mod_1 - mod_2 == 2)                                           // situ. 2
            if (digits_map[2].size() > 0) digits_map[2].pop_back();            // situ. 2.1
            else { digits_map[1].pop_back(); digits_map[1].pop_back(); }       // situ. 2.2
        else if (mod_2 - mod_1 == 1) digits_map[2].pop_back();                 // situ. 3
        else if (mod_1 - mod_2 == 1) digits_map[1].pop_back();                 // situ. 4
        digits_result.insert(digits_result.cend(), digits_map[1].cbegin(), digits_map[1].cend());
        digits_result.insert(digits_result.cend(), digits_map[2].cbegin(), digits_map[2].cend());
        // 3. 输出结果
        sort(digits_result.begin(), digits_result.end(), greater<int>());
        if (digits_result.empty()) return "";
        if (digits_result[0] == 0) return "0";
        string result{ "" };
        for (auto i : digits_result) result += i + '0';
        return result;
    }
};
```