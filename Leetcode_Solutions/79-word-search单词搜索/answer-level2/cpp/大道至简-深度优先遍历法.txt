**思路：**通过题中所给条件，我们知道 是将word字符串与二维数组board数组匹配的过程，那我们的思路可以自然而然的得到对于任意坐标（i，j）在所给的坐标方位内一共有四种方向,对任意方向进行深度遍历，直到不满足条件。另外，因为dfs可能不止一次会搜索到同样的坐标，为了加以区分 我们需要一个二维数组**vis[i][j]**来进行辨别时候已经搜索到。
```
dr_i[4] = {0, 0, 1, -1};
dr_j[4] = {1, -1, 0, 0};
```

```
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty())  //边界条件判断
          return false;
        if(word.empty())
          return true;
        
        n=board.size(),m=board[0].size();  
        len=word.size();
        vis.assign(n,vector<bool> (m));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dfs(i,j,0,board,word))  //二重循环 依次搜索
                  return true;
            }
        }
        return false;
    }
private:
       int n,m,len;
       vector<vector<bool>>vis;
       static const int di[4];
       static const int dj[4];
    
    bool check(int x,int y)//对坐标进行判断，越界还是已经探索过
    {
        if(x<0||x>=n||y<0||y>=m||vis[x][y])
          return false;
        return true;
    }

    bool dfs(int x,int y,int index,vector<vector<char>>&board,string &word)
    {
        if(board[x][y]!=word[index]) return false;//
    
        if(index==len-1) return true;

        //dfs模板
        vis[x][y]=true;//坐标(x,y)判定
        for(int t=0;t<4;t++)
        {
            int new_x=x+dr_i[t];
            int new_y=y+dr_j[t];

            if(check(new_x,new_y))
            {
                vis[new_x][new_y]=true;
                if(dfs(new_x,new_y,index+1,board,word))
                  return true;
                vis[new_x][new_y]=false;
            }
        }
        vis[x][y]=false;//将原来的坐标变为未探索过的情形
        return false;
    }
};

const int Solution::dr_i[4] = {0, 0, 1, -1};
const int Solution::dr_j[4] = {1, -1, 0, 0};
```
