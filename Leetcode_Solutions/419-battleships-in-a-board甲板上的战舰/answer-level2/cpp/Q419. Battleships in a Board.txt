如果题设没有特殊规则和要求的话，常规做法就是使用BFS或者DFS扫描，计算连通图的个数。
但是题目要求只扫描一次，且O(1)的额外空间，那么就只能从题目给出的特殊规则出发了。
特殊规则：连通图是1xN或者Nx1的长条形的，且不会相交（之间有.分隔）。
解法：扫描到X时，如果上方或者左方也是X，则不计数，否则计数加1。
```
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int nCount = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'X') {
                    if (i > 0 && board[i - 1][j] == 'X' ||
                        j > 0 && board[i][j - 1] == 'X')
                        continue;
                    ++nCount;
                }
            }
        }
        return nCount;
    }
};
```
我果真不适合写题解，写文章啊！