### 解题思路

### 代码

```cpp
class Solution 
{
public:
    vector<int> father;

    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n=edges.size();

        father=vector<int>(n+1);
        for(int i=1;i<=n;i++) father[i]=i;

        for(auto e:edges)
        {
            int Top0=FindTop(e[0]);
            int Top1=FindTop(e[1]);

            if(Top0!=Top1) father[Top0]=Top1;
            else return e;
        }

        return vector<int>();
    }

    int FindTop(int pre)
    {
        if(father[pre]==pre) return pre;

        //路径压缩,将pre到top路径上的所有父亲设置为top
        father[pre]=FindTop(father[pre]);

        return father[pre];
    }
};
```