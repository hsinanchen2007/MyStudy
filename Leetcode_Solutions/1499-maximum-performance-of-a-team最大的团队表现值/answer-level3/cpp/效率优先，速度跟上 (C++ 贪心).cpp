### 复杂度

时间复杂度 $O(n \log n) + O(n \log k)$，空间复杂度 $O(n + k)$。

### 大致思路

比较像贪心过程吧。

#### 排序

大体上是优先考虑效率，随后再考虑速度。

首先，我们将速度 `speed` 与效率 `efficiency` 在 C++ 中组成数对，储存在变量 `pr` 中，以进行排序。譬如，对于题目的范例
```
speed      = [ 2, 10, 3, 1, 5, 8]
efficiency = [ 5,  4, 3, 9, 7, 2]
```
我们重新组合并排序成如下的量：
```
pr
first  (efficiency) = [ 9, 7, 5,  4, 3, 2]
second (speed)      = [ 1, 5, 2, 10, 3, 8]
```
这一步的消耗是 $O(n \log n)$。

#### 在效率确定情况下考虑速度

这里的算法会影响到程序是否能避免耗时过长从而正常 AC。

**前 k 个员工**

譬如对于 `k = 3` 的情况而言，我们首先需要考虑，不多于 3 个员工也可能很好地完成工作。

我们就会发现，
- 1 个员工：结果 9
- 2 个员工：结果 42
- 3 个员工：结果 40

结果的最大值我们储存在 `result = 42` 中。

随后，我们将前 `k = 3` 个员工的速度储存在一个多元集合中 `st`，即
```
st = { 1, 2, 5 }
```
并且将上述所有元素的和记为 `spd_sum = 8`。集合 `st` 将会储存速度最快的 `k` 个员工的速度。

**以后的员工**

对于 4 个或以上员工的情况下，我们先判断该员工的速度，是否比集合 `st` (速度最快的员工) 中最慢的速度要快一些。
譬如，第 4 个员工速度为 10，而 `st` 的最低速度是 1；我们就需要对这种情况作讨论。
那么我们将这第 4 个员工列入速度最快的员工中，并且踢出速度最慢的值 `1`，即让速度集合 `st` 变为
```
st = { 2, 5, 10 }
```
我们同时需要更新一下 `spd_num` 的值。`spd_num` 显然等于 `2 + 5 + 10 = 17`。它的更新方式是通过减去曾经的最小值 `1`，再加上当前员工速度 `10` 得到的，即
```
spd_num = 8 - 1 + 10 = 17
```
然后我们更新一下结果。当前员工的效率是 4，而速度和是 17，因此结果是 `17 * 4 = 68`。我们就此更新结果 `result = 68`。当然，这恰好也是最终结果。

刚刚讨论的是第 4 位员工的速度比最快速度的集合 `st` 还要高的情况。如果速度更低，那么就直接跳过即可。

上述过程的最坏复杂度是 $O(n \log k)$；因为集合的插入复杂度是 $O(\log k)$，而遍历一遍所有员工需要 $O(n)$。之所以是 **最坏** 复杂度情况，是因为遍历过程中，很可能会发现，后来的员工的速度并不比前面员工快，因此会跳过不少插入操作。

如果不考虑集合插入，更新一次 (不多于) k 个最快员工的速度 `spd_num` 的过程是 $O(1)$。我认为这是编写程序时，考虑算法复杂度的难点。假使我们每次更新 `spd_num` 都是对速度集合 `st` 所有 k 元素求和，那么其复杂度就是 $O(k)$ 了；从而程序整体复杂度是 $O(n \log n) + O(n \log k) + O(n k)$。这种情况下，程序就很有可能不能 AC。

### 代码

耗时在 150ms - 250ms 之间。

尽管题目说数据会很大，但由于题目的数据并没有太离谱，因此我们只需要把 int 拓展为 long long (定义为 LL)，就能避免溢出。

```c++
typedef long long LL;

class Solution {
    // 比较效率与速度，大小按 greater 来处理
    // 效率 (efficiency, first) 优先考虑，速度 (speed, second) 随后考虑
    struct PairCompare {
        inline bool operator()(pair<LL, LL>& p1, pair<LL, LL>& p2) {
            if (p1.first == p2.first) return p1.second > p2.second;
            else return p1.first > p2.first;
        }
    };
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // 首先对效率与速度作排序
        vector<pair<LL, LL>> pr; pr.reserve(n);
        for (int i = 0; i < n; ++i)
            pr.push_back(make_pair((LL)efficiency[i], (LL)speed[i]));
        sort(pr.begin(), pr.end(), PairCompare());
        // 预定义
        LL spd_sum = 0;   // 最快的 (不多于) k 个速度的和
        multiset<LL> st;  // 最快速度的集合
        LL result = 0;    // 待返回的结果
        // 随后从依效率从高到低顺序，遍历所有员工
        for (int i = 0; i < n; ++i) {
            // 如果员工数没有到最大值 k，则把所有员工的速度都考虑进来
            if (i < k) {
                spd_sum += pr[i].second;
                st.insert(pr[i].second);
            }
            // 如果员工数已经大于 k，且当前员工速度比较快，那么 fire 掉最慢的员工，无论该员工效率如何
            else if (pr[i].second > *st.begin()) {
                spd_sum += pr[i].second - *st.begin();
                st.erase(st.begin());
                st.insert(pr[i].second);
            }
            // 更新一下结果
            result = max(spd_sum * pr[i].first, result);
        }
        return int(result % (LL)1000000007);
    }
};
```
