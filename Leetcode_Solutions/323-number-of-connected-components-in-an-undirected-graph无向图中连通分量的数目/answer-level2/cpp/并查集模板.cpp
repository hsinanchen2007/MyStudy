### 解题思路


### 代码

```cpp
class Solution {
public:
    int father[100010];
    int height[100010];

    void Initial(int n){//初始化
        for(int i=0;i<n;i++){
            father[i]=i;
            height[i]=0;
        }
    }

    int Find(int x){//找根
        if(father[x]!=x) father[x]=Find(father[x]);//路径压缩
        return father[x];
    }

    void Union(int x,int y){//合并结点
        x=Find(x);
        y=Find(y);
        if(x!=y){
            if(height[x]<height[y]) father[x]=y;
            else if(height[x]>height[y]) father[y]=x;
            else{
                father[y]=x;
                height[x]++;
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        Initial(n);
        int components=0;//连通分量个数
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            Union(a,b);
        }
        for(int i=0;i<n;i++){
            //cout<<i<<"父亲是"<<Find(i)<<endl;
            if(Find(i)==i){
                components++;
            }
        }
        return components;
    }
};
```