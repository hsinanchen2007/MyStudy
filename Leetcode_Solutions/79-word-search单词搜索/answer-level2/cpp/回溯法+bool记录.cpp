回溯法，并利用used二维数组记录board元素使用情况；
注意先更新used，再递归调用，之后检查used是否需要恢复；
结束条件为下一个寻找的下标d超出有效值
```
class Solution {
public:
    bool huisu(vector<vector<char>>& board, vector<vector<bool>>& used, string& word,int curi,int curj,int d)
    {
        if(d>=word.size())
        return true;
        bool uup,ddo,lle,rri;
        uup=ddo=lle=rri=false;
        if(curi>0 && !used[curi-1][curj] && board[curi-1][curj]==word[d])
        {
            used[curi-1][curj]=true;
            uup=huisu(board,used,word,curi-1,curj,d+1);
            if(!uup)
            used[curi-1][curj]=false;
        }
        if(curi<board.size()-1 && !used[curi+1][curj] && board[curi+1][curj]==word[d])
        {
            used[curi+1][curj]=true;
            ddo=huisu(board,used,word,curi+1,curj,d+1);
            if(!ddo)
            used[curi+1][curj]=false;
        }
        if(curj>0 && !used[curi][curj-1] && board[curi][curj-1]==word[d])
        {
            used[curi][curj-1]=true;
            lle=huisu(board,used,word,curi,curj-1,d+1);
            if(!lle)
            used[curi][curj-1]=false;
        }
        if(curj<board[0].size()-1 && !used[curi][curj+1] && board[curi][curj+1]==word[d])
        {
            used[curi][curj+1]=true;
            rri=huisu(board,used,word,curi,curj+1,d+1);
            if(!rri)
            used[curi][curj+1]=false;
        }
        return (uup||ddo||lle||rri);
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        int k=word.size();
        if(k==0)
        return true;
        int m=board.size();
        if(m==0)
        return false;
        int n=board[0].size();
        if(n==0)
        return false;
        vector<vector<bool>> used(m,vector<bool>(n,false));
        for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
        {
            if(board[i][j]==word[0])
            {
                used[i][j]=true;
                if(huisu(board,used,word,i,j,1))
                return true;
                else
                used[i][j]=false;
            }
        }
        return false;
        
    }
};
```
