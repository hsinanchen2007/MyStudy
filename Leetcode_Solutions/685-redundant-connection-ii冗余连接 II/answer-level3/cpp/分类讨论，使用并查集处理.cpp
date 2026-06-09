#### 解题思路：
图中的顶点数目与 `edges` 的大小相同，针对多余的一条边，分两种情况进行讨论：

1. 如果多余的边连到了非根结点 `A` 上，此时记录A的两个父节点 `B` 和 `C`，假设在 `edges` 中 `B->A` 出现在 `C->A` 之前，于是遍历 `edges` 中除去 `C->A` 这条边的其他边，对每条边连接的两个顶点进行并查集 `merge` 操作（也称之为 `connect` ），合并过程中有如下两种情况：

  - 如果合并中发现某条边合并的两个顶点已经属于同一个集合，即合并中发现存在环，这说明多余的边不是 `C->A` 这条边，设置最终返回边为 `C->B`;
  
  - 如果合并中没有发现环，设置最终返回边为 `C->A`;

2. 如果多余的边连到了根结点上，那么直接对 `edges` 中所有边连接的两个顶点进行 `connect` 操作。
  
  - 如果遍历过程中，发现某两个节点已经隶属于同一个集合，此时返回这条边即可。

#### 代码：
代码实现如下，实际测速最快 4ms，最慢大概 20ms。

```C++ [-C++]
struct UnionFind{
    public:
        vector<int> sz,parent;
        UnionFind(const int n){
            sz.reserve(n);
            sz.assign(n, 1);
            parent.reserve(n);
            for(int i = 0; i < n; ++i)
                parent.push_back(i);
        }

    int findParent(int x){
        while(x != parent[x]){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    
    bool merge(int x, int y){
        int p = findParent(x);
        int q = findParent(y);
        if(p == q) return false;
        else if(sz[p] >= sz[q]){
            sz[p] += sz[q];
            parent[q] = p;
        }
        else{
            sz[q] += sz[p];
            parent[p] = q;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> indegree;   // 记录每个节点的入度
        indegree.reserve(edges.size()+1);
        indegree.assign(edges.size()+1, 0);
        int abnormalNode = -1;  // 记录入度为 2 的节点
        vector<int> preNodeVec(2,-1);// 记录入度为 2 的节点的两个父节点
        vector<int> preNodeMap;      // 记录每个节点的父节点
        preNodeMap.reserve(edges.size()+1);
        preNodeMap.assign(edges.size()+1, -1);
        
        // 统计每个节点的入度，寻找是否存在入度为2的节点
        for(auto &e : edges){
            // 如果发现某个节点入度为 2，保存这个节点，同时保存这个节点的两个父节点
            if(++indegree[e[1]] > 1) {
                abnormalNode = e[1];
                preNodeVec[0] =preNodeMap[e[1]];
                preNodeVec[1] = e[0];
                break;
            }
            preNodeMap[e[1]] = e[0];
        }
        
        vector<int> ans;
        ans.reserve(2);
        ans.assign(2,abnormalNode);
        
        UnionFind uf(edges.size()+1);
        // 如果存在入度为 2 的节点，删除靠后的那条边，测试是否有环
        // 如果有环，说明返回边是前一条边，如果无环，说明返回边应该是靠后的那条边
        if(abnormalNode!=-1){
            ans[0] = preNodeVec[1];
            bool find = true;
            for(auto&e:edges){
                if(e[0] == ans[0] && e[1] == abnormalNode) continue;
                else {
                    if(!uf.merge(e[0], e[1])){
                        ans[0] = preNodeVec[0];
                        break;
                    }
                }
            }
        }
        // 如果没有入度为 2 的边，直接遍历 edges 中所有的边
        // 如果这条边合并了 2 个早已属于同一个集合的顶点，则返回这条边
        else{
            for(auto&e:edges)
                if(!uf.merge(e[0], e[1])){
                    ans[0] = e[0];
                    ans[1] = e[1];
                    break;
                }
        }
        return ans;
    }
};
```