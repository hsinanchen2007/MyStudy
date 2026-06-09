1.剪枝
2.调用函数不要使用形参，用引用变量做参
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()<=0||word.size()<=0)
            return false;

        vector<vector<bool>> judge(board.size(),vector<bool>(board[0].size(),false));//判断节点是否走过

        int pathLength=0;//记录已走过的字符长
        int rows=board.size();
        int cols=board[0].size();

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(board[i][j]==word[0])   
                {
                    if(hasPathCore(word,pathLength,board,rows,cols,i,j,judge))
                        return true;
                }
            }
        }

        return false;
    }

    bool hasPathCore(string wd,int pathLen,vector<vector<char>> & bd,int rows,int cols,int row,int col,vector<vector<bool>> & jd)
    {
        if(pathLen==wd.size())
            return true;

        bool hasPath=false;

        if(row>=0&&row<rows&&col>=0&&col<cols)
        if(jd[row][col]==false&&bd[row][col]==wd[pathLen])
        {
            pathLen++;
            jd[row][col]=true;
            if(hasPath=hasPathCore(wd,pathLen,bd,rows,cols,row,col+1,jd))
                return true;
            if(hasPath=hasPathCore(wd,pathLen,bd,rows,cols,row+1,col,jd))
                return true;
            if(hasPath=hasPathCore(wd,pathLen,bd,rows,cols,row-1,col,jd))
                return true;
            if(hasPath=hasPathCore(wd,pathLen,bd,rows,cols,row,col-1,jd))
                return true;
            

            if(!hasPath)
            {
                pathLen--;
                jd[row][col]=false;
            }   
        }

        return hasPath;
    }
};