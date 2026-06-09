### 解题思路
step1.找到一个能够开始的地方开始
step2.先将当前坐标标记入路径，然后看看四周哪一步能走；
step3.如果能走，走过去，调用step2.
      如果都不能走，标记此方向为死路
step4.如果所有方向都是死路，取消标记此点

### 代码

```cpp
class Solution {
public:
    int table[210][210]={0};

    bool exist(vector<vector<char>>& board, string word) {
        bool res=false;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0]) 
                {

                    bool tmp = dfs(board,word,i,j,0);
                    res = res||tmp;
                }
            }
        }
        return res;

    }

    int dfs(vector<vector<char>>& board,string word,int x,int y,int len)
    {
        table[x][y]=1;
        if(len==word.size()-1) return true;
        int flag[4]={false};//left,down,right,up
        if(Is_available(board,word,x-1,y,len+1)) flag[0]=dfs(board,word,x-1,y,len+1);
        else flag[0]=false;
        if(Is_available(board,word,x,y+1,len+1)) flag[1]=dfs(board,word,x,y+1,len+1);
        else flag[1]=false;
        if(Is_available(board,word,x+1,y,len+1)) flag[2]=dfs(board,word,x+1,y,len+1);
        else flag[2]=false;
        if(Is_available(board,word,x,y-1,len+1)) flag[3]=dfs(board,word,x,y-1,len+1);
        else flag[3]=false;
        if (!(flag[0]||flag[1]||flag[2]||flag[3])) table[x][y]=0;
        return (flag[0]||flag[1]||flag[2]||flag[3]);
    }
    bool Is_available(vector<vector<char>>& board,string word,int x,int y,int len)
    {
        if(x<0 || x>=board.size()) return false;
        if(y<0 || y>=board[0].size()) return false;
        if(table[x][y]==1) return false;
        if(board[x][y]==word[len]) return true;
        else return false;
    }
};
```