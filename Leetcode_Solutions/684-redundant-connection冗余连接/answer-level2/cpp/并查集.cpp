### 解题思路
1. 初始时，每个节点的都是一个独立的集合，扫一遍整个二维数组即可实现初始化
2. 根据边[u,v]合并集合u和集合v，如果某次合并时，发现u和v已经是同一个集合了，那么这条边[u,v]多余

### 代码

```cpp
class Solution {
public:
    unordered_map<int,int> uf;
    int n;

    void init(vector<vector<int>>& edges){
        n = edges.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 2; j++) uf[edges[i][j]] = edges[i][j];
        }
    }

    int find(int x){
        return x == uf[x] ? x : uf[x] = find(uf[x]);
    }

    bool merge(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return true;
        else{
            uf[y] = x;
            return false;
        }
    }
 
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init(edges);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(merge(edges[i][0], edges[i][1])) ans = edges[i];
        }
        return ans;
    }
};
```