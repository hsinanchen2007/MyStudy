```
class Solution {
public:
    int mount;
    int dic[3][2]={{-1,-1},{-1,0},{-1,1}};
    int m;
    int totalNQueens(int n) {
     vector<string> mp;
    string temp="";
    for(int i=0;i<n;i++) temp+='.';
    for(int i=0;i<n;i++) mp.push_back(temp);//创建好了棋盘
    m=mp.size();
    dfs(mp,0);//回溯
   return mount;
    }
    void dfs(vector<string>& mp,int k)
    {
        if(k==m)
        {
            mount++;
            return;
        }
        for(int i=0;i<mp[k].size();i++)
        {
            if(judge(mp,k,i)) 
            {
                mp[k][i]='Q';
                dfs(mp,k+1);
                mp[k][i]='.';
            }
            
        }
        return;
    }
    bool judge(vector<string>& mp,int x,int y)
    {
         //上
         int up=x;
         while(up>=0)
         {
             up+=dic[1][0];
             if(up>=0&&mp[up][y]=='Q') return false;
         }
         //左上
         int xu=x,yu=y;
         while(xu>=0&&yu>=0)
         {
             xu+=dic[0][0];
             yu+=dic[0][1];
             if(xu>=0&&yu>=0&&mp[xu][yu]=='Q') return false;
         }
         //右上
         while(x>=0&&y<m)
         {
             x+=dic[2][0];
             y+=dic[2][1];
             if(x>=0&&y<m&&mp[x][y]=='Q') return false;
         }
         return true;
    }
};
```
