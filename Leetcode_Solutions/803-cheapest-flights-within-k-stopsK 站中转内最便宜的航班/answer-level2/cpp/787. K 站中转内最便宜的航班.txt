### 解题思路
dfs
### 代码

```cpp
class Solution {
public:
    int res=INT_MAX;
    int book[101];
    int mp[101][101];
    void dfs(int n,int pos, int dst,int cnt,int k,int sum){
        if(cnt>k) return ;
        for(int i=0;i<n;i++){
            if(mp[pos][i]!=0&&book[i]==0&&sum+mp[pos][i]<res){
                if(i==dst){
                    res=sum+mp[pos][i];continue;
                }
                book[i]=1;
                dfs(n,i,dst,cnt+1,k,sum+mp[pos][i]);
                book[i]=0;
            }
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int i,j;
        for(i=0;i<flights.size();i++){
            mp[flights[i][0]][flights[i][1]]=flights[i][2];
        }
        book[src]=1;
        dfs(n,src,dst,0,K,0);
        if(res==INT_MAX) return -1;
        return res;
    }
};
```