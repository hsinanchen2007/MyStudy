看了一下发现没有把52题里比较巧妙的位运算的方法应用到这道题里的题解
于是想通过一些改动把N皇后II问题中的位运算方法应用到这道题当中
因为位运算的写法确实更加简洁明了一些
也是刚刚才开始刷，因此代码风格有很多不好的地方
看一下思路就好

**思路：**
使用dfs
三个整形l,r,m用来表示当前棋盘上的哪个点可以放置皇后，二进制位为 1 代表不能放置，0 代表可以放置

**其中的位运算：**
i & (-i), 当于i and (not i + 1)，
其结果是取出这个二进制数 i 最右边的那个1
例：0011010经过运算为0000010
运算过程： = 0011010 + （1100101 + 1)。

		  0011010
		& 1100110
		——————————
		  0000010
		
这样，i 就表示该行右起第一个可以放子的位置

思路可以参照52题的这个题解：https://leetcode-cn.com/problems/n-queens-ii/solution/dfs-wei-yun-suan-jian-zhi-by-makeex/

```
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // 初始化一个棋盘，将棋盘中的点初始化为'.'
        vector<string> board(n, string(n, '.'));
        queen(0,0,0,0,n,board);
        return ans;
    }
    void queen(int l, int r, int m, int k, int n, vector<string> board){
        if(k == n){
            ans.push_back(board);
            return;
        }
        for(int i = ~(l|r|m)&((1<<n)-1); i;){
            int p = i&-i;
            board[k][log2(p)] = 'Q';
            queen((l|(i&-i))<<1,(r|(i&-i))>>1,m|(i&-i),k+1,n, board);
            board[k][log2(p)] = '.';
            i-=p;
        }
    }
private:
    vector<vector<string>> ans;
};
```

