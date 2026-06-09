利用`d(i,j) = h(i) + h(j) - h(LCA(i, j))*2`(**d距离，h高度，LCA最近公共祖先**)。

求`ans[i]`即`d(i,0)+d(i,1)+...d(i,N) = N*h(i)+ (所有h的和)+ 2*(h(p0(i))*S(h(p0(i))) + h(p1(i))*(S(h(p2(i)) - S(h(p1(i)))) +  h(p2(i))*(S(h(p3(i)) - S(h(p2(i)))) +... )` (**pk(i)代表i的k级祖先，p0(i)即i自身，为了一致性所以用p0(i)代替i;S是以i为根的子树的结点总数**)。

因为`h(pk+1(i)) - h(pk(i)) = 1`，所以`h(p0(i))*S(h(p0(i))) + h(p1(i))*(S(h(p2(i)) - S(h(p1(i)))) +  h(p2(i))*(S(h(p3(i)) - S(h(p2(i))))+...`可以以拆项重组化简为`S(h(p0(i)))+S(h(p1(i)))+...`一直加到非0的最上级祖先。
```cpp
class Solution {
public:
    vector<vector<int>> G;
    vector<int> h, S, ans;
    int dfs(int x, int d, int p){
        h[x] = d;
        for(auto &n : G[x]) if(p != n) S[x] += dfs(n, d + 1, x);
        return S[x];
    }
    void dfs2(int x, int p){
        if(x == 0) S[x] = 0; else S[x] += S[p];
        for(auto &n: G[x]) if(p != n) dfs2(n, x);
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        G.resize(N), h.resize(N), S.resize(N, 1), ans.resize(N);
        for(auto &x :edges){ G[x[0]].push_back(x[1]); G[x[1]].push_back(x[0]); }
        dfs(0, 0, -1); dfs2(0, -1);
        int o = accumulate(h.begin(), h.end(), 0);
        for(int i = 0; i < N; ++i) ans[i] = N*h[i]+o-2*S[i];
        return ans;
    }
};
```
