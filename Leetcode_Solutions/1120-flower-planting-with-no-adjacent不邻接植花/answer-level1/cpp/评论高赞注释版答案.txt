### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> Adj;
        vector<int> v;
        for(int i=0;i<N;i++)                    //邻接矩阵初始化
            Adj.push_back(v);
        for(int i=0;i<paths.size();i++)         //将paths中的值赋给矩阵中
        {
            Adj[paths[i][0]-1].push_back(paths[i][1]-1);
            Adj[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        
        vector<int> ans(N,0);                   //构造一个有N个初值为0的容器
        for(int i=0;i<N;i++)                    //表示初始N个花园均未上色
        {
            set<int> color{1,2,3,4};       //set的erase来直接去掉重复的颜色
            for(int k=0;k<Adj[i].size();k++)
                color.erase(ans[Adj[i][k]]);    //最关键一步，删去邻近的颜色
            ans[i]=*(color.begin());            //去重后的颜色赋给ans[i]
        }
        return ans;
    }
};
```