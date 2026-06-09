其实一开始做这道题的时候，我并不是很明白题意，在我的印象之中，判断数独是否有解是一个非常困难的事情，因为数独是一个NP问题。

后来我看了解答，大致明白了题意，即只要判断行列块不包含重复元素即可，这样就能保证数独有解吗，我也不知道，但是按照这个思路，其实做起来就很简单了，稍微需要注意的就是块的问题 。
![image.png](https://pic.leetcode-cn.com/8023fa70ad14f83c18d775a67413e487978d69c9dc1baa655494b8584f191e4f-image.png)

对于每一块，从左到右分别标为0到8，则每一块的第(i,j)号位置可以记做
(gridNumber / 3 * 3 + i, gridNumber % 3 * 3 +j)，这样就很简单了。

使用hash数组来判断是否重复。
```
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            if(!(checkCol(i,board)&&checkRow(i,board)&&checkGrid(i,board))) return false;
        }
        return true;
    }
    bool checkRow(int rowNumber, vector<vector<char>>& board) {
        int hash[10];
        memset(hash,0, sizeof(hash));
        for(int i=0;i<9;i++) {
            if(board[rowNumber][i]=='.') continue;
            if(hash[board[rowNumber][i]-'0']==0) hash[board[rowNumber][i]-'0']=1;
            else return false;
        }
        return true;
    }
    bool checkCol(int colNumber, vector<vector<char>>& board) {
        int hash[10];
        memset(hash,0, sizeof(hash));
        for(int i=0;i<9;i++) {
            if(board[i][colNumber]=='.') continue;
            if(hash[board[i][colNumber]-'0']==0) hash[board[i][colNumber]-'0']=1;
            else return false;
        }
        return true;
    }
    bool checkGrid(int gridNumber, vector<vector<char>>& board) {
        int hash[10];
        memset(hash,0, sizeof(hash));
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                int x = gridNumber/3 * 3+i, y = gridNumber%3 *3+j;
                if(board[x][y]=='.') continue;
                if(hash[board[x][y]-'0']==0) hash[(int)board[x][y]-'0'] = 1;
                else return false;
            }
        }
        return true;
    }

};

```
