思路：dfs，递归，回溯
tips：dfs函数用实参，不要用形参，不然效率差10倍（时间and空间） 【原理：实参传递的是指针或引用】
```
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i,int j, int w){
        if(board[i][j]!=word[w]) return false;
        if(w==word.length()-1) return true;
        char tmp=board[i][j]; board[i][j]=0;
        if( (i-1>=0 && dfs(board, word, i-1, j, w+1)) 
        || (j+1<=board[0].size()-1 && dfs(board, word, i, j+1, w+1))
        || (i+1<=board.size()-1 && dfs(board, word, i+1, j, w+1))
        || (j-1>=0 && dfs(board, word, i, j-1, w+1)) ) return true;
        board[i][j]=tmp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++) if(dfs(board, word, i, j, 0)) return true;
        }
        return false;
    }
};
```

> -------------------------------------------------
> > \>\>\>[**我的算法题本 - 算法菜鸟之路**](https://github.com/lorwin0130/Algorithm-newbie)
> 会记录做过题的**不同解法、思路、套路总结以及个人思考**
> 欢迎各位大佬**来讨论呀**，欢迎**star (U^_^U)** 
> -------------------------------------------------
