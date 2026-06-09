首先用一个字符记录单词的首字母，然后遍历整个二维数组，如果当前字符和前面记录的首字母相同，则开始深度递归。
递归的每一步验证当前层的字符是不是和单词中对应的字符相同，如果不同，立刻剪去这棵子树。
此外，当找到目标单词时，其余未深搜的子树不再进行递归，直接保存答案退出。
```
bool flag[203][203];
    int ceng;
    string best,tmpstr,tmpword;
    void dfs(vector<vector<char>>& board,int i,int j,int t)
    {
        if(tmpword[t]!=tmpstr[t])
            return;
        if(t==ceng-1)
        {
            best=tmpstr;
            return;
        }
        if(i<board.size()-1 && flag[i+1][j]==false && best.size()==0)
        {
            tmpstr.push_back(board[i+1][j]);
            flag[i+1][j]=true;
            dfs(board,i+1,j,t+1);       //向下递归
            flag[i+1][j]=false;
            tmpstr.pop_back();
        }
        if(i>0 &&flag[i-1][j]==false && best.size()==0)
        {
            tmpstr.push_back(board[i-1][j]);
            flag[i-1][j]=true;
            dfs(board,i-1,j,t+1);       //向上递归
            flag[i-1][j]=false;
            tmpstr.pop_back();
        }
        if(j<board[0].size()-1 && flag[i][j+1]==false && best.size()==0)
        {
            tmpstr.push_back(board[i][j+1]);
            flag[i][j+1]=true;
            dfs(board,i,j+1,t+1);       //向右递归
            flag[i][j+1]=false;
            tmpstr.pop_back();
        }
        if(j>0 && flag[i][j-1]==false && best.size()==0)
        {
            tmpstr.push_back(board[i][j-1]);
            flag[i][j-1]=true;
            dfs(board,i,j-1,t+1);       //向左递归
            flag[i][j-1]=false;
            tmpstr.pop_back();
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int len1=board.size();
        if(len1==0)
            return false;
        int len2=board[0].size();
        int wsize=word.size();
        ceng=wsize;
        tmpword=word;
        if(len1==1 && len2==0)
            return false;
        if(len1==1 && len2==1)
        {
            string one;
            one.push_back(board[0][0]);
            if(wsize==len2 && word==one)
                return true;
            else 
                return false;
        }
        memset(flag,0,sizeof(flag));
        char head=word[0];
        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<len2;j++)
            {
                if(board[i][j]==head)
                {
                    tmpstr.push_back(board[i][j]);
                    flag[i][j]=true;
                    dfs(board,i,j,0);
                    tmpstr.pop_back();
                    flag[i][j]=false;
                    if(best.size()>0)
                        return true;
                }
            }
        }
        return false;
    }
```
