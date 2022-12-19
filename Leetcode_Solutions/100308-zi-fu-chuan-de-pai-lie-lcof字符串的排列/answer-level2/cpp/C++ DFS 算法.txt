标准DFS操作
关键在剪纸去重
```
if (i > 0 && s[i] == s[i - 1] && !visited[i - 1]) 
                continue;
```


```

class Solution {
public:
    vector<string> permutation(string s) 
    {
        vector<string> res;
        int n = s.size();
        string out(n,'0');
        vector<bool> visited(n,false);
        sort(s.begin(),s.end());
        dfs(s,res, out,visited, 0,n);
        return res;
    }
    
    void dfs(string& s,vector<string>& res,string& out,vector<bool>& visited,int index, int n)
    {
        if (index == n)
        {
            res.emplace_back(out);
            return;
        }
        for (int i=0;i<n;++i)
        {
            //剪枝去重复
            if (i > 0 && s[i] == s[i - 1] && !visited[i - 1]) 
                continue;
            
            if (visited[i])
                continue;
  
            visited[i] = true;
            out[index] = s[i];
            dfs(s,res,out,visited,index+1,n);
            visited[i] = false;
        }
        return;
    }
}; 
```
