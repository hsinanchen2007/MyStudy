# 解法一：
先构建图，然后深度遍历图去计算有几个连通子树
```
class Solution {
public:
    bool isSim(const string& s1, const string& s2) {
        if (s1.size() != s2.size()) return false;
        int diff = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                ++diff;
                if (diff > 2) return false;
            }
        }
        return true;
    }
    void dfs(vector<vector<int> >& g, int i, vector<bool>& seen) {
        seen[i] = true;
        for (auto j : g[i]) {
            if (!seen[j]) {
                dfs(g, j, seen);
            }
        }
    }
    int numSimilarGroups(vector<string>& A) {
        int N = A.size();
        vector<vector<int > > g(N);
        for (int i = 0; i < N; ++i) {
            g[i].push_back(i);
            for (int j = i + 1; j < N; ++j) {
                if (isSim(A[i], A[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector<bool> seen(N, false);
        int res = 0;
        for (int i = 0; i < N; ++i) {
            if (!seen[i]) {
                ++res;
                dfs(g, i, seen);
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/9e7e002154435837c390e5aba732c6c780f433666d85b427d1fae524bcf572e8-image.png)

# 解法二：
并查集

```
class Solution {
public:
    bool isSim(const string& s1, const string& s2) {
        if (s1.size() != s2.size()) return false;
        int diff = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                ++diff;
                if (diff > 2) return false;
            }
        }
        return true;
    }
    vector<int> F;
    int father(int x) {
        if (x != F[x]) F[x] = father(F[x]);
        return F[x];
    }
    int numSimilarGroups(vector<string>& A) {
        int N = A.size();
        F.resize(N);
        for (int i = 0; i < N; ++i) F[i] = i;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (isSim(A[i], A[j])) {
                    F[father(i)] = father(j);
                }
            }
        }
        unordered_set<int> s;
        for (int i = 0; i < N; ++i) {
            s.insert(father(i));
        }
        return s.size();
    }
};
```
![image.png](https://pic.leetcode-cn.com/337e9affc35f49ab811ebb265f7397c2b46e3f8f4ff6d9f859f36474f7db4bd8-image.png)
