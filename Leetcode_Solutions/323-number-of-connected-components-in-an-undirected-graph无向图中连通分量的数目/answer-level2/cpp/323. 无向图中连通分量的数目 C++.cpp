### 解题思路
连通分量：不连通的图是由2个或者2个以上的连通子图组成的。这些不相交的连通子图称为图的连通分量。
1.并查集：将所有边连接起来，有几个根节点，即有几个连通分量
2.DFS+visit：DFS时遍历到的节点全部置位为-1，for循环计数执行了几遍DFS，遇到-1就continue，否则执行遍历并计数+1

### 代码

```cpp
class Solution {
public:
    int findParent(int a, vector<int> &parent)
    {
        while (parent[a] != a) {
            a = parent[a];
        }

        return a;
    }


    void join(int a, int b, vector<int> &parent)
    {
        int parenta = findParent(a, parent);
        int parentb = findParent(b, parent);
        //连接的是根节点
        if (parenta != parentb) {
            parent[parenta] = parentb;
        }

        return;
    }

    int countComponents(int n, vector<vector<int>> &edges)
    {
        vector<int> parent;
        int result = 0;
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }

        for (int i = 0; i < edges.size(); i++) {
            join(edges[i][0], edges[i][1], parent);
        }

        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == i) {
                result++;
            }
        }

        return result;
    }
};
```