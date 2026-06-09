### 解题思路

### 代码
对于安排过的情况可以直接return，使用map记录或者用set都可以
```cpp
class Solution {
public:
    int count=0;
    map<vector<int>,int> mp;
    map<vector<int>,int> mp2;
    void dfs(vector<int> temp,vector<int> vis,vector<int>& A)
    {
        if(temp.size()==A.size())
        {
            if(mp.find(temp)==mp.end())
            {
                mp[temp]=1;
                ++count;
            }
            return;
        }
        int end=temp[temp.size()-1];
        if(mp2.find(temp)==mp2.end())
            mp2[temp]=1;
        else
            return ;
        for(int i=0;i<A.size();++i)
        {
            if(vis[i]==0)
            {
                int sum=A[i]+end;
                int f=(int)sqrt(sum);
                if(pow(f,2)==sum)
                {
                    temp.push_back(A[i]);
                    vis[i]=1;
                    dfs(temp,vis,A);
                    temp.pop_back();
                    vis[i]=0;
                }
            }
        }
    }
    int numSquarefulPerms(vector<int>& A) {
        vector<int> temp;
        vector<int> vis(A.size(),0);
        for(int i=0;i<A.size();++i)
        {
            vis[i]=1;
            temp.push_back(A[i]);
            dfs(temp,vis,A);
            vis[i]=0;
            temp.pop_back();
        }
        return count;
    }
};
```