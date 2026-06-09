执行用时|内存消耗|语言
--|--|--
0 ms|6.1MB|Cpp

提交代码：

```cpp
static constexpr int counts[] = { 9, 56, 320, 1624, 7152, 26016, 72912, 140704, 140704 };
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int res = 0;
        for (int i = m - 1; i < n; i++) {
            res += counts[i];
        }
        return res;
    }
};
```

当然，`counts`数组的结果我是离线用DFS算的，而且没有优化，所以比较慢：

```cpp
// self
#define S -1

static vector<vector<int>> trans = {
    { S, 0, 2, 0, 0, 0, 4, 0, 5 },
    { 0, S, 0, 0, 0, 0, 0, 5, 0 },
    { 2, 0, S, 0, 0, 0, 5, 0, 6 },
    { 0, 0, 0, S, 0, 5, 0, 0, 0 },
    { 0, 0, 0, 0, S, 0, 0, 0, 0 },
    { 0, 0, 0, 5, 0, S, 0, 0, 0 },
    { 4, 0, 5, 0, 0, 0, S, 0, 8 },
    { 0, 5, 0, 0, 0, 0, 0, S, 0 },
    { 5, 0, 6, 0, 0, 0, 8, 0, S }
};

class Solution {
public:
    int numberOfPatterns(int m, int n)
    {
        count = 0;
        is5pressed = false;
        this->m = m;
        this->n = n;
        for (int i = 1; i <= 9; i++) {
            dfs({ i }, i, 1);
        }
        return count;
    }

private:
    void dfs(set<int> seq, int now, int len)
    {
        if (len >= m && len <= n) {
            count++;
        } else if (len > n) {
            return;
        }
        auto& t = trans[now - 1];
        for (int i = 1; i <= 9; i++) {
            int n = t[i - 1];
            if (n == S) {
                continue;
            } else if ((seq.find(i) == seq.end()) && ((n == 0) || (n != 0 && seq.find(n) != seq.end()))) {
                seq.insert(i);
                dfs(seq, i, len + 1);
                seq.erase(i);
            }
        }
    }
    int count;
    bool is5pressed;
    int m, n;
};
```