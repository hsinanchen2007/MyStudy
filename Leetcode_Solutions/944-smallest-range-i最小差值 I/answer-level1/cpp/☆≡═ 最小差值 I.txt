1. 把A中的数字放置在数轴上，B中的数字由A中数字加x组成，-K <= X <= K。
2. 为了使得B的最大值和最小值之间差值最小，即B区间长度最小。
3. 可以将给A的最小值加K，给A的最大值减K，B区间的长度最小为0或者A区间长度减2K。
4. minmax_element 可以在线性时间内得到 A 最小值和最大值的迭代器。
```
class Solution {
public:
    int smallestRangeI(const vector<int>& A, const int K) {
        if (A.empty()) return 0;
        const auto [low, high] = minmax_element(A.begin(), A.end());
        return max(0, *high - *low - 2 * K);
    }
};
```
