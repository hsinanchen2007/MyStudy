第一次参加竞赛，留个念~ 第三题没做出来 T-T

比如拿 [9, 17, 5] 举例，首先我们先对数组排序得到 [5, 9, 17]
然后，我们应当留意到最大数 17 = 9 + 5 + 3，
因此，17 的前身是 3 = 17 - 9 - 5。
随后，我们把数组改成 [5, 9, 3]，并进行排序得到 [3, 5, 9]，下一轮就讨论 9，以此类推。
(但是这里原则上不应该排序，排序的复杂度 $O(n \log n)$，这里如果只移动最大数，排序复杂度可以降到 $O(n)$；用堆插入的话，可以进一步降到 $O(\log n)$)

成功的判据是，如果最后数组全是 1 (即数组的和是数组长度 3)；
失败的判据是任何一个数出现了 0 或负数，譬如 [1, 1, 1, 2] 的例子通过上面的过程会得到 [1, 1, 1, -1]。
因此，依照这个思路，整个算法的复杂度最好的情况下是 $O(T \log n + n \log n)$，其中 $T$ 是看脸的迭代次数。
(但是最初竞赛时提交的代码还是 $O(T n \log n + n \log n)$)

以此类推就能解决问题~
程序中
- `tmp_sum` 是当前的数组的和，对于 [5, 9, 17] 而言是 31；
- `tmp_sum_minus` 是需要被减去的数的和，对于 [5, 9, 17] 而言是 14；
- `scaler` 是需要被减的数的倍数。比如对于 [5, 9, 31] 而言，31 - 14 = 17 还是最大数，因此不如干脆 31 - 14 * 2 = 9，即让 `scaler = 2`。这可以避免输入样例类似于 `[1000000000, 1]` 时会产生的超时。(借鉴了 [LightT](https://leetcode-cn.com/problems/construct-target-array-with-multiple-sums/comments/243999) 的评论) 因此，在加了 `scaler` 变量后，看脸的迭代次数 $T$ 应当不会大于 $n$。
- 感谢 [@陈曦](https://leetcode-cn.com/problems/construct-target-array-with-multiple-sums/solution/yong-jian-fa-dao-tui-jie-ti-by-zhu-zhen-yu-ajz34/244737) 指出的问题。尽管尚能通过测试数据，但 `scaler` 仍然有可能写得不对。我想严格的办法应该是用取余是否为零判断，但总是在想能不能用一些小技巧避免取余的代码 =ω=

这道题由于求和后 int 会溢出，所以用 long long。

**最大堆优化的代码** $O(T \log n + n \log n)$ 60ms，需要开额外的向量 (堆)

```c++
class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) return target[0] == 1;     // 首先讨论数组长度只有 1 的情况
        priority_queue<int> heap;                          // 构建最大堆
        for (int val : target) {
            if (val <= 0) return false;                    // 不可能有任何元素小于零
            heap.push(val);
        }
        long long tmp_sum = 0;
        for (int val : target) tmp_sum += val;              // 记录每次数组的和，用 sum(target) 初始化
        while (tmp_sum > target.size()) {                   // 如果数组仍然不是 [1, 1, ..., 1]，即数组和仍然不是数组长度，则循环
            int top_val = heap.top(); heap.pop();           // 记录数组的最大值，并弹出最大值
            long long tmp_sum_minus = (tmp_sum - top_val);  // 譬如 [5, 9, 17] 的情况，则 tmp_sum_minus = 5 + 9 = 14
            if (top_val <= tmp_sum_minus) return false;     // 如果最大值 17 小于或等于要被减去的数 14，那么这题就是无解的
            long long scaler = ((long long)top_val - heap.top() - 1) / tmp_sum_minus + 1;  // Additional thanks to comment from @陈曦
            if (top_val - tmp_sum_minus * scaler <= 0) return false;  // This value could be smaller than 0, so we make another check
            heap.push(top_val - tmp_sum_minus * scaler);    // 当然 [5, 9, 17] 有解，因此把 17 - 14 * 1 = 3 代入到最大堆中
            tmp_sum -= tmp_sum_minus * scaler;              // 最后别忘记把数组和更新一下
        }
        return true;
    }
};
```

**最初提交的，跟文档较相似的代码** $O(T n \log n + n \log n)$ ~180ms，不需要开额外的向量，在 `[1000000000, 1]` 的输入下会超时

```c++
class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) return target[0] == 1;
        if (target[0] <= 0) return false;
        sort(target.begin(), target.end());
        long long tmp_sum = 0; for (int val : target) tmp_sum += val;
        while (tmp_sum > target.size()) {
            int idx_last = int(target.size()) - 1;
            long long tmp_sum_minus = (tmp_sum - target[idx_last]);
            if (target[idx_last] < tmp_sum_minus) return false;
            target[idx_last] -= tmp_sum_minus;
            tmp_sum -= tmp_sum_minus;
            sort(target.begin(), target.end());
        }
        return true;
    }
};
```
