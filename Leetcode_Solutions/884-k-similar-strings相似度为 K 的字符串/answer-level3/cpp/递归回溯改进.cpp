### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int kSimilarity(string A, string B) {
        unordered_map<string,int> mp;
        string now(A);
        int res=INT_MAX;
        dfs(mp,now,res,0,0,B);
        return res;
    }
    void dfs(unordered_map<string,int>& mp,string &now,int &res,int i,int used,string &B){
        if(used>=res)return;
        if(mp.find(now)!=mp.end()&&mp[now]<=used)return;
        if(now==B){
            res=used;
            mp[now]=used;
            return;
        }
        if(now[i]==B[i])dfs(mp,now,res,i+1,used,B);
        for(int j=i+1;j<B.size();j++){
            if(now[j]==B[i]){
                iter_swap(now.begin()+i,now.begin()+j);
                dfs(mp,now,res,i+1,used+1,B);
                iter_swap(now.begin()+i,now.begin()+j);
            }
        }
        mp[now]=used;
    }
};
```