今天来学习并查集
```
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        int n=edges.size();
        vector<int>f(n+1);//f[i]是第i个节点的根结点，终极boss
        for(int i=1;i<=n;i++){f[i]=i;}
        for(auto edge:edges){
            int a = find(f,edge[0]);//一对中第一个数的终极boss
            int b = find(f,edge[1]);//一对中第二个数的终极boss
            if(a!=b){//如果不同的头儿 就后者服从前者
                f[b] = a;
            }else{// 同一个头儿的话 就可以返回了
                res = {edge[0],edge[1]};
                return res;
            }
        }
        return res;
    }
    int find(vector<int>&f,int x)
    {
        while(f[x]!=x)
        {
            x=f[x];
        }
        return x;
    }
};
```
