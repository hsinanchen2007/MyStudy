```
class Solution {
public:
/*题目类型 
带返回值的dfs 连通搜索
这个题需要注意的点很多！
*/
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        if(m<=0) return false;
        int n=board[0].size();
        if(n==0) return false;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(dfs(board,word,i,j,0)) return true;
        }
        return false;

    }
/*dfs参数中用于描述所有的搜索状态
dfs传递二维矩阵和字符串参数时都要用引用！！不要传递形参，效率很低
str :template string
int u:是搜索的第几个字符
int x:x 坐标
int y:y坐标

*/
    bool dfs(vector<vector<char>> &board, string & word, int x, int y, int len)
    {
        if(word[len]!=board[x][y]) return false;//非合法状态
        if(len == word.size()-1) return true;//合法且为目标状态 输出

        //合法但非目标状态
        int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};//搜索棋盘/矩阵问题技巧！！定义偏移量
        char nowc=board[x][y];
        board[x][y]='.';//标记位置，表示用过了不能再用
        for(int i=0;i<4;i++)
        {
            int a=x+dx[i],b=y+dy[i];//依次搜索四个方向
            if(a>=0&&a<board.size()&&b>=0&&b<board[0].size())//小心！！可能越界
                 if(dfs(board,word,a,b,len+1)) return true;            
                 //直接return dfs(...)不行么？不可以 因为逻辑关系不是直接等于dfs的结果
                 //而是如果有一个为true 则为true 否则为false(回溯)
                 //如果直接return,相当于只对board[0][0]去搜到头然后直接返回true or false，
                 //而题目意思是:对每一个格子都搜 都返回false了才返回false!
        }
        /*回溯*/
        board[x][y]=nowc;//回溯！！恢复初始状态
         //80%的暴力搜索题目都需要回溯
        return false; 
    }
};
```
