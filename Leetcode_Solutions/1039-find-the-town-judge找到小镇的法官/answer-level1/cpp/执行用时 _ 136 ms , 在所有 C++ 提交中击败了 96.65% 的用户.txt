
### 代码

```cpp
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<vector<int>> Adj;
        vector<int> v;
        for(int i=0;i<=N;i++)                    //matrix的初始化
            Adj.push_back(v);
        
        for(int i=0;i<trust.size();i++)          //matrix的赋值
            Adj[trust[i][1]].push_back(trust[i][0]);
        
        int index=0;
        for(int i=1;i<=N;i++)
            if(Adj[i].size()==N-1)              //如果有一个人被所有人信任
                {
                    index=i;
                }
        if(index==0)return -1;
        for(int i=1;i<=N;i++)
            for(int j=0;j<Adj[i].size();j++)    //如果这个人信任别人则不是法官
                if(Adj[i][j]==index)return -1;
        return index;
    }
};
```