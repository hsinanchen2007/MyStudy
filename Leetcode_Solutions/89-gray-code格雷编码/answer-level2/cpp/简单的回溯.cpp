```
class Solution {
public:
    vector<int> res;
    vector<bool> vis;//用vis数组来标记是否访问
    
    vector<int> grayCode(int n) {
    vis=vector<bool>(1<<n,0);

    dfs(0,n);
    return res;
    }
    
    void dfs(int cur,int n)
    { 
        if(res.size()==(1<<n))
            return ;
        res.push_back(cur);
        vis[cur]=true;

        for(int i=0;i<n;i++)
        {
            int next = cur^(1<<i); //这里改变cur的某一位，用异或
            if(vis[next]) continue;
            
            dfs(next,n);
        }
        //vis[cur] = false; //不需要返回，一步到位 故可不必还原状态
        return ;
    }
};
```
