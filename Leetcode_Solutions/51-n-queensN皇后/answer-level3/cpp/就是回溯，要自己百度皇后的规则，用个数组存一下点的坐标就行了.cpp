### 解题思路
a[n]存储结果,a.size==n时出现一组解，更改v的值，加入ans中

 if(a[j]==i||i+a.size()==j+a[j]||a[j]+a.size()==j+i) return false;这个判断语句需要点初中数学

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> ans;
    vector<int>a;
    vector<string> v;
    bool queen(int i)
    {
            for(int j=0;j<a.size();j++)
            {
                if(a[j]==i||i+a.size()==j+a[j]||a[j]+a.size()==j+i) return false;
            }    
            return true;
    }
    void dfs(int n)
    {
        if(a.size()==n)
        {
           for(int i=0;i<n;i++)
           {
               v[i][a[i]]='Q';
           }
           ans.push_back(v);
           for(int i=0;i<n;i++)
           {
               v[i][a[i]]='.';
           }
           return;
        }
        for(int i=0;i<n;i++)
       {
           if(a.size()==0||queen(i)==true)
           {
               a.push_back(i);
               dfs(n);
               a.pop_back();
           }
       }
       return;
    }
    vector<vector<string>> solveNQueens(int n) {
      char m[n+1];
     for(int i=0;i<n;i++)
      {
          m[i]='.';
      }
      m[n]='\0';
      for(int i=0;i<n;i++)
      {
          v.push_back(m);
      }
      dfs(n);
      return ans;
    }
};
```