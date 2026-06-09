
首先拿到题目要想到怎么在 $O\left(n\right)$ 的复杂度内求出某一个点到所有点的距离和。
方法是维护每棵子树到子树根的距离和，和每棵子树去除根节点的节点数，然后设法转移即可。

设 $sum[p]$ 表示 $p$ 节点所在的子树中，每个节点到 $p$ 的距离和；
设 $cnt[p]$ 表示 $p$ 节点所在子树大小(不包含根节点)。

则对于 $p$ 的父亲 $fa$ 有: 
$$ sum[fa]=\sum_{p} \left( sum[p]+cnt[p]+1 \right) $$
$$ cnt[fa]=\sum_{p} cnt[p] $$

因此，最朴素的做法是 $O\left(n^2\right)$ 的，即将每一个节点作为根节点走一遍dfs。


现在我们试图通过转移在 $O\left(1\right)$ 次数内求出所有点的距离和。

例如对于下图，对于节点 $3$ ，其答案恰好可以通过节点 $2$ 转移。

```
  0
 / \
1   2
   /|\
  3 4 5
  |
  6
```

节点 $3$ 的距离和恰好为除去包含节点 $3$ 的子树的节点（即 $[0,1,2,4,5]$ ）到 $3$ 的距离和，加上其子树(即 $[6]$ )到 $3$ 的距离和。
其中，前者在已知节点 $2$ 到全体距离和的情况下，可以转移得到，方法和之前提到的朴素做法思想类似；而后者是朴素做法的计算结果。



现设 $ans[fa]$ 表示树上所有节点到 $fa$ 节点的距离和，则对于其子节点 $p$ 有:
$$ ans[p]=\left(ans[fa]-sum[p]-cnt[p]-1\right)+\left(n-cnt[p]-1\right)+sum[p] $$

因此，本题可以在两遍dfs的复杂度下完成，总体时间复杂度为 $O\left(n\right)$ 。


```C++
class Solution {
    int n;
    vector<int> Edges[10010];
    int cnt[10010];
    int sum[10010];
    vector<int> ans;
    bool vis[10010];

    void dfs(int p){
        for (auto &e:Edges[p]){
            if (!vis[e]){
                vis[e]=true;
                dfs(e);
                sum[p]+=sum[e]+cnt[e]+1;
                cnt[p]+=cnt[e]+1;
            } 
        }
    }

    void dfs2(int p,int fa){
        ans[p]=ans[fa]+n-(cnt[p]+1)*2;
        //ans[p]=(ans[fa]-sum[p]-cnt[p]-1)+(n-cnt[p]-1)+sum[p];
        for (auto e:Edges[p]){
            if (!vis[e]){
                vis[e]=true;
                dfs2(e,p);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& x) {
        n=N;
        for(auto &e:x){
            Edges[e[0]].push_back(e[1]);
            Edges[e[1]].push_back(e[0]);
        }
        vis[0]=true;
        dfs(0);
        ans.resize(n);
        ans[0]=sum[0];
        memset(vis+1,0,sizeof(bool)*(n-1));
        for (auto e:Edges[0]){
            vis[e]=true;
            dfs2(e,0);
        }
        return ans;
    }
};
```
*Comment: 这种题属于非常套路的题目，做多了就很容易想出来*
*另外，可以选择定义cnt[p]包含根节点去做*
*与其说这是一道深搜题，不若说是一道树形dp问题*
*更多题解可以参考我的* [博客](https://lemon-412.github.io/)