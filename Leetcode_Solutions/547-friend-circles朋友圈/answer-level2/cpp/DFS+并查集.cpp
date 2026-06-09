### 解题思路
此处撰写解题思路

### 代码

```
//DFS:
vector<bool> vis;
void dfs(vector<vector<int>> &M, int i) {
    vis[i] = true;
    for (int j = 0; j < M.size(); j++) {
        if (!vis[j] && M[i][j] == 1) {
            dfs(M, j);
        }
    }
    return;
}
int findCircleNum(vector<vector<int>>& M) {
    int n = M.size();
    if (n == 0) {
        return 0;
    }
    vis = vector<bool>(n, false);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            res++;
            dfs(M, i);
        }
    }
    return res;
}
```


```cpp
//并查集
class Solution {
public:
    int parent[210];
    int findRoot(int x) {
        while (x != parent[x]) {
            x = parent[x];
        }
        return x;
    }
    void Union(int x, int y) {
        int x_root = findRoot(x);
        int y_root = findRoot(y);
        if (x_root != y_root) {
            parent[x_root] =y_root;
        }
    }
    void init() {
        for (int i = 0; i < 210; i++) {
            parent[i] = i;
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
        init(); //不能忘记init
        for (int i = 0; i < M.size(); i++) {
            for (int j = i+1; j < M.size(); j++) {
                if (M[i][j] == 1){
                    Union(i, j);
                }
            }
        }

        //一次遍历找到所有祖先节点，即为朋友圈的个数
        
        int res = 0;
        for (int i = 0; i < M.size(); i++) {
            if (i == parent[i]) {
                res++;
            }
        }
        return res;
    }
};
```

