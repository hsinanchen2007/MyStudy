c++ 并查集 ，看了大佬的思路，才知道可以把行列 合并起来，=_= , 我是按照同行同列将 石头链接起来，看存在几个集合，每个集合都可以删除到最后一个石头，所以可删除的石头就是 `总石头数 - 集合数`

总结了一些其它 并查集的相关问题  https://blog.csdn.net/junqing_wu/article/details/104697226


```cpp
class DSU{

public:
    int* parent;
    int cnt;

    DSU(int n):parent(new int[n]),cnt(n){
        for(int i=0;i<n;i++) parent[i] = i;
    }

    int find(int a){
        if(a != parent[a]) parent[a] = find(parent[a]);
        return parent[a];
    }

    void union_elem(int a,int b){
        int aroot = find(a);
        int broot = find(b);
        if(aroot!=broot){
            parent[aroot] = broot;
            cnt-=1;
        }
    }

};



class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        if(!n) return 0;
        DSU uf(n);
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(stones[i][0] == stones[j][0] || 
                    stones[i][1] == stones[j][1]){
                        uf.union_elem(i,j);
                    }
            }
        }
        return n-uf.cnt;
    }
};
```