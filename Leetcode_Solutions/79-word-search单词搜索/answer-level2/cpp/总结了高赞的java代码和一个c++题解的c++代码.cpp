注释按全局变量->exist()->dfs()的顺序写的，这样看逻辑比较顺畅
```c++
class Solution {
public:
    vector<vector<bool> > mark;
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};//方向
    int m,n;//矩阵的长和宽
    vector<vector<char>> Board;//为了可以调用全局变量
    string Word;//全局变量
    bool dfs(int i, int j, int start)//i,j是在图中的位置，start是word的游标
    {
        if(Board[i][j]==Word[start])//如果当前字符匹配，前往下一个字符
        {
            if(start==Word.length()-1) return true;//整个word全中
            mark[i][j] = true;//锁上当前字符
            for(int k=0;k<4;k++)//遍历四个方向
            {
                int newx =i+ dir[k][0];
                int newy =j+ dir[k][1];
                if(newx>=0 && newy >= 0 && newx<m&& newy<n && mark[newx][newy]==false)//下个方向合法
                {
                    if(dfs(newx,newy,start+1) ==true)//递归去下个方向
                        return true;
                }
            }
            mark[i][j] = false;//如果不能继续走下去，解锁，回溯
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty())return false;//空用例
        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++)//构造mark
        {
            vector<bool> t;
            for(int j=0;j<n;j++)t.push_back(false);
            mark.push_back(t);
        }
        Board = board;
        Word = word;//给全局变量赋值
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])//在全图找起点
                {
                    bool flag= dfs(i, j, 0);
                    if(flag==true) return flag;//如果找到路了，直接返回
                }
            }
        }
        return false;
    }
    
};
```c++
