### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        if(n<=0)
            return {};

        if(n==1)
            return{{"Q"}};
        vector<vector<int>>res;
        vector<int>out;
        vector<int>visited(n+1,0);
        generateP(0,n,visited,out,res);
        //cout<<res[0][0]<<res[0][1]<<res[0][2]<<res[0][3];
        string nofdot = "";
        for(int i = 0;i <n;i++)
        {
            nofdot += '.';
        }
       // cout<<res[0][0]<<res[0][1]<<res[0][2]<<res[0][3];
        
        vector<vector<string>> ans;
        for(int i = 0; i < res.size(); i++)
        {
            vector<string> oneans;
            for(int j = 0;j < res[i].size();j++)
            {
                string cur = nofdot;
                cur[res[i][j]-1] = 'Q';
                oneans.push_back(cur);
            }
            ans.push_back(oneans);
        }
        return ans;
    }
    void generateP(int index,int n,vector<int>& visited,vector<int>& out,vector<vector<int>>&res)
    {
        if(index == n)
        {
            res.push_back(out);
            return;
        }
        for(int i = 1; i <=n ;i++ )
        {
            if(visited[i]==0)
            {
                bool flag = true;
                for(int pre = 0;pre < out.size();pre++)
                {
                    if(abs(i-out[pre]) == abs(index-pre))
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                {
                    out.push_back(i);
                    visited[i] = 1;
                    generateP(index+1,n,visited,out,res);
                    visited[i] = 0;
                    out.pop_back();
                }
            }
        }
    }
};
```