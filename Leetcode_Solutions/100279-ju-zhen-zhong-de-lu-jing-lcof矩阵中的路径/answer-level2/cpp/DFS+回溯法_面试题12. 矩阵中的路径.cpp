### 解题思路
类似于八皇后问题，比较简单的思路是，遍历board矩阵，从矩阵中找到与字符串第一个字符相等的值。从这个值开始，将其上下左右的值与字符串第二个字符进行比较，找到相等的值，如果不相等回溯到原值并从其他方向进行比较；重复上述的操作，直到找到字符串最后一个字符为止。这里面有两点需要思考：
1. 当前值之后的下一轮操作，需要确定查询方向：上下左右{(x+1,y),(x-1,y),(x,y+1),(x,y-1)}
2. 对于已经遍历过的值，需要进行标记，通常的做法是设置标记数组，每次查询标记数组该值是否遍历过；一种比较好的方法是直接将已经遍历过的值改为矩阵中不存在的值，最后恢复即可

其他需要注意的地方：遍历矩阵时需要考虑矩阵的边界，容易出错(简直害人不浅啊！！！)。
### 代码

```cpp
class Solution {
public:
bool exist(std::vector<std::vector<char>> &board, const std::string &word) {
    if (board.empty() || board.size() == 0 || board[0].size() == 0) {
        return false;
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if(board[i][j]==word[0]){
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
    }

    return false;
}

private:
bool dfs(std::vector<std::vector<char>> &board, const std::string &word, int index, int x, int y) {
    //判断是否越界和是否继续递归
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[index]) {
        return false;
    }

    //递归结束
    if (index == word.size() - 1) {
        return true;
    }

    //直接改变矩阵中的值，防止重复搜索
    //比使用mark[][]数组存储访问标志要简单
    char tmp = board[x][y];
    board[x][y] = '.';

    //递归查找，查询的四个方向：上下左右{(x+1,y),(x-1,y),(x,y+1),(x,y-1)}
    if (dfs(board, word, index + 1, x, y + 1)
        || dfs(board, word, index + 1, x, y - 1)
        || dfs(board, word, index + 1, x + 1, y)
        || dfs(board, word, index + 1, x - 1, y)) {
        return true;
    }
    //恢复为原值
    board[x][y] = tmp;

    return false;
}
};
```