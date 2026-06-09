### 解题思路
典型的Union Find解法，代码比较清晰。

### 代码

```cpp
class Solution {
private:
    vector<int> parent;
    vector<int> len ;
    int count = 0;
public:
    int find(int x){
        while(parent[x] != x){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void bond(int p,int q){
        int rootp = find(p);
        int rootq = find(q);
        if(rootp == rootq) return;
        
        //小树接到大树下面，使整个结构较平衡
        if(len[rootp]>len[rootq]){
            parent[rootq] = rootp;
            len[rootp] += len[rootq];
        }else{
            parent[rootp] = rootq;
            len[rootq] += len[rootp];
        }
        count--;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        count = n;
        for(int i = 0; i < n; ++i){
            //路径压缩
            parent.push_back(i);
            len.push_back(1);
        }

        for(auto t:edges){
            bond(t[0],t[1]);
        }
        return count;
    }
};
```