### 解题思路

参考了 [@amchor](/u/amchor/) 的题解，改写为 C++ 版。

state变量表示已占用的数字，使用值传递可以方便的回溯。

### 代码

```cpp
class Solution {
private:
    unordered_map<int, unordered_map<int, int>> dict = {
        {1, {{3, 2}, {7, 4}, {9, 5}}},
        {2, {{8, 5}}},
        {3, {{9, 6}, {7, 5}, {1, 2}}},
        {4, {{6, 5}}},
        {5, {}},
        {6, {{4, 5}}},
        {7, {{1, 4}, {9, 8}, {3, 5}}},
        {8, {{2, 5}}},
        {9, {{1, 5}, {7, 8}, {3, 6}}}
    };
    int M;
    int N;
public:
    int numberOfPatterns(int m, int n) {
        M = m;
        N = n;
        int res = 0;
        res += 4 * dfs(1 << 1, 1, 1);
        res += 4 * dfs(1 << 2, 2, 1);
        res += dfs(1 << 5, 5, 1);
        return res;
    }

    int dfs(int state, int cur, int count) {
        if(count == N)
            return 1;

        int res = count < M ? 0 : 1;
        for(int i=1; i<10; i++) {
            // i数字用过
            if(state & (1 << i))
                continue;
            // 除了必须经过一点才能到达的，其余都是能直接到达的
            if(dict[cur][i] == 0 || ((1 << dict[cur][i]) & state) != 0)
                res += dfs(state | (1 << i), i, count + 1);
        }
        return res;
    }
};

```