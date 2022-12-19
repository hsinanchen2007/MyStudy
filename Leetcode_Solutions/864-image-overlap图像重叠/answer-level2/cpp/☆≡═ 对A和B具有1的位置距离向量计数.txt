```
A = [[1,1,0],
     [0,1,0],
     [0,1,0]]
B = [[0,0,0],
     [0,1,1],
     [0,0,1]]
```
1. 把 $B$ 左移一格，上移一格后，$A$ 和 $B$ 重叠的格子数量最多，为$3$个。
2. 这三组重叠的 $1$ 共有的特点是 行坐标 差$1$，列坐标 差$1$。
3. 可以遍历 $A$ 的所有坐标和 $B$ 的所有坐标，计算距离向量，然后选择距离向量相同的最多点对数量，就是最大的重叠。
4. $A$ 和 $B$ 中可能有很多$0$，可以先枚举 $A$ 和 $B$ 中值为 $1$ 的坐标。
5. 这个题中行和列最多只有$30$，可以把行和列编码进同一个$int$变量中。
6. 如果 $A$ 和 $B$ 都比较稀疏，比如长宽为 $n$，而且$A$, $B$中 $1$ 的数量也为 $n$ 时，时间复杂度为 $O(n^2)$
```c++
class Solution {
public:
    int largestOverlap(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        int ans = 0;
        vector<int> flat_a, flat_b;
        unordered_map<int, int> distance_count;
        for (int r = 0; r < A.size(); ++r) {
            for (int c = 0; c < B.size(); ++c) {
                if (A[r][c]) flat_a.push_back(flat(r, c));
                if (B[r][c]) flat_b.push_back(flat(r, c));
            }
        }
        for (const auto& a : flat_a) {
            for (const auto& b : flat_b) {
                ++distance_count[a - b];
            }
        }
        for (const auto& c : distance_count)
            ans = max(ans, c.second);
        return ans;
    }
private:
    static inline int flat(const int r, const int c) { return (r<<6) + c; }
};
```
