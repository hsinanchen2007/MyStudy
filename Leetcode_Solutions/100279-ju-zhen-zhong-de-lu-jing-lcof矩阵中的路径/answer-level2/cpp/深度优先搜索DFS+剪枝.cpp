矩阵的搜索问题使用DFS解决
注意最开始剪枝（越界判断，不满足条件）
`if(i>=board.size()||i<0||j>=board[0].size()||j<0||board[i][j]!=word[n]) return false;`
另外给矩阵中的元素设置一个标记防止重复访问
 ` board[i][j]='#';//避免重复访问`
在深搜完之后，恢复元素的值
` board[i][j]=temp;`
具体代码如下：



```
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        if(row==0)
        return false;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(dfs(board,word,i,j,0))//第一步剪枝的动作在DFS里面进行 board[i][j]!=word[n];
                return true;
            }
        }
        return false;
        }
        bool dfs(vector<vector<char>>& board, string &word, int i, int j, int n)
        {
            if(i>=board.size()||i<0||j>=board[0].size()||j<0||board[i][j]!=word[n]) return false;//越界时和不满足时直接返回false；
            if(n==word.size()-1) return true;//循环终止条件
            char temp=board[i][j];//标记已经访问过的节点
            board[i][j]='#';//避免重复访问
            bool res=dfs(board,word,i+1,j,n+1) || dfs(board,word,i,j+1,n+1) || 
                     dfs(board,word,i-1,j,n+1) || dfs(board,word,i,j-1,n+1); 

            board[i][j]=temp;
            return res;
        }
   
};
```

