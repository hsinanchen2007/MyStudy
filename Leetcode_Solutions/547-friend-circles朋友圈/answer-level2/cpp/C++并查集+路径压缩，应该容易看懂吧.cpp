### 解题思路


### 代码

```cpp
class Solution {
public:
    int find(vector<int>& uf,int x){
        while(uf[x]!=x){
            uf[x]=uf[uf[x]];//路径压缩
            x=uf[x];
        }
        return x;
    }
    void Union(vector<int>& uf,int x,int y){
        x=find(uf,x);y=find(uf,y);
        uf[x]=y;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        vector<int> uf(n);
        for(int i=0;i<n;i++) uf[i]=i;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){//由于对称，完全可以省略i前面的
                if(M[i][j]==1)
                    Union(uf,i,j);
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
            if(uf[i]==i)//关键
                count+=1;
        return count;
    }
};
```