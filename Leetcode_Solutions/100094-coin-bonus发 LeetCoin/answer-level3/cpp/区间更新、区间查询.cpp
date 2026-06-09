### 解题思路
~~线段树~~
树状数组
区间求和，可以用线段树的地方，基本上都可以使用树状数组。
适用于区间更新、区间查询场景，建两个树状数组~~使用场景较少~~。

### 代码

```cpp
class Solution {
public:
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        vector<int> ret;
        ret.clear();
        init(n, leadership);
        bitIndexTree.init(n+1);
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i][0] == 1) {
                int idx = dfn[operations[i][1]];
                int val = operations[i][2];
                bitIndexTree.add(idx, idx, val);
            } else if (operations[i][0] == 2) {
                int st = dfn[operations[i][1]];
                int ed = end[operations[i][1]];
                int val = operations[i][2];
                bitIndexTree.add(st, ed, val);
            } else if (operations[i][0] == 3) {
                int st = dfn[operations[i][1]];
                int ed = end[operations[i][1]];
                //cout << st << ' ' << ed << " op3" << endl;
                // for (int i = 1; i <= n; i++) {
                //     cout << "val " << bitIndexTree(i, i) << endl;
                // }
                int ans = bitIndexTree.sum(st, ed);
                ret.push_back(ans);
            }
        }
        return ret;
    }
private:
    void init(int n, vector<vector<int>>& leadership) {
        root = 0;
        timestep = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(end, 0, sizeof(end));
        memset(in, 0, sizeof(in));
        for (int i = 0; i < N; i++) {
            G[i].clear();
        }
        for (int i = 0; i < leadership.size(); i++) {
            int u = leadership[i][0];
            int v = leadership[i][1];
            in[v]++;
            G[u].push_back(v);
        }
        for (int i = 1; i <= n; i++) {
            if (!in[i]) {
                root = i;
                break;
            }
        }
        dfs(root);
        // for (int i = 1; i <= n; i++) {
        //     cout << dfn[i] << ' ' << end[i] << endl;
        // }
    }
    void dfs(int u) {
        dfn[u] = ++timestep;
        end[u] = dfn[u];
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            dfs(v);
        }
        end[u] = timestep;
    }
    static const int N = 5e4 + 10;
    static const int mod = 1e9 + 7;
    vector<int> G[N];
    int dfn[N];
    int end[N];
    int in[N];
    int root;
    int timestep;
    // 树状数组
    class BitIndexTree {
    public:
        using LL = long long;
        void init(int len) {
            memset(sum1, 0, sizeof(sum1));
            memset(sum2, 0, sizeof(sum2));
            n = len;
        }
        void add(int left, int right, int val) {
            add(left, val);
            add(right+1, -val);
        }
        
        LL sum(int left, int right) {
            return (sum(right) - sum(left-1) + mod) % mod;
        }
    private:
        LL sum1[N];
        LL sum2[N];
        int n;
        inline LL lowbit(LL x) {
            return x & (-x);
        }
        void add(int idx, int val) {
            LL x = idx;
            while(idx <= n) {
                sum1[idx] = (sum1[idx] + val + mod) % mod;
                sum2[idx] = ((sum2[idx] + (x-1)*val) % mod + mod) % mod;
                idx += lowbit(idx);
            }
        }
        LL sum(int m) {
            LL ans = 0;
            int x = m;
            while (m) {
                ans += ((x * sum1[m]) % mod - sum2[m] + mod) % mod;
                ans %= mod;
                m -= lowbit(m);
            }
            return ans;
        }
    } bitIndexTree;
};
```