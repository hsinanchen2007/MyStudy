### 解题思路
执行用时 : 2500 ms , 在所有 C++ 提交中击败了 5.07% 的用户 内存消耗 : 45 MB , 在所有 C++ 提交中击败了 5.61% 的用户
dfs将递归条件由节点没访问变为节点现有最小长度比最新最小长度大。
### 代码

```cpp
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> min_length(N+1,-1);
        int edgeCounts=times.size();
        vector<vector<vector<int>>> adj(N+1);
        for(int i=0;i<edgeCounts;i++)
        {
            int v=times[i][0];
            int w=times[i][1];
            int l=times[i][2];
            vector<int> temp;
            temp.push_back(w);
            temp.push_back(l);
            adj[v].push_back(temp);
        }
                
        dfs(K,0,min_length,adj);
        
        int result=-1;        
        for(int j=1;j<N+1;j++)
        {
            if(min_length[j]==-1) {result=-1;break;}
            else if(min_length[j]>result){
                result=min_length[j];
            }
        }
        return result;
    }
    void dfs(int K, int length, vector<int>& min_length,vector<vector<vector<int>>>& adj)
    {
        min_length[K]=length;
        for(int i=0;i<adj[K].size();i++)
        {                
            int w=adj[K][i][0];
            int l=adj[K][i][1];
            if(min_length[w]==-1||min_length[w]>l+min_length[K]) dfs(w,l+min_length[K],min_length,adj);
        }
    }
};
```