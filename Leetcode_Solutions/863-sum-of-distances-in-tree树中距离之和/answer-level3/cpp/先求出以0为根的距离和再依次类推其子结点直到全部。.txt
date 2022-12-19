- 假设求出了一个根结点的距离和。其子结点的和等于res[fa] + (n - size[son]) - size[son];
- 其中的n - size[son]表示除了以子结点为根的子树的其他结点数量和。因为相比到父结点那些结点
- 全部需要多一点距离。所以相加。同理-size[son]是因为这些结点到父结点的距离与到这个子结点的
- 距离相比全都少了一点。所以要减去这么多个子结点的和。我也是看其他大佬的代码结合看图中的例子
- 结合才看懂。多看看例子的图应该就能明白了。

```
class Solution {
public:
    vector<vector<int>> gh;
    vector<int> dist; //i点的所有子结点到i的距离之和
    vector<int> size; //以i点为根的树的结点数量和(包括i结点本身)
    vector<int> res;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        gh.resize(n); dist.resize(n); size.resize(n); res.resize(n);
        for (const auto& v : edges) {
            gh[v[0]].emplace_back(v[1]);
            gh[v[1]].emplace_back(v[0]);
        }
        dfs1(0, -1);
        res[0] = dist[0];
        dfs2(n, 0, -1);
        return res;
    }
    //求出以0为根的距离之和且求出了分别以i为根的子树结点数量和
    void dfs1(int cur, int par) {
        dist[cur] = 0;
        size[cur] = 1;
        for (auto i : gh[cur]) {
            if (i == par) continue;
            dfs1(i, cur);
            dist[cur] += dist[i] + size[i];
            size[cur] += size[i];
        }
    }
    //从0开始往下递归推出子树。再子树推算出子子树直到所有。
    void dfs2(int n, int cur, int par) {
        for (auto i : gh[cur]) {
            if (i == par) continue;
            res[i] = res[cur] + (n - size[i]) - size[i];
            dfs2(n, i, cur);
        }
    }
};
```
