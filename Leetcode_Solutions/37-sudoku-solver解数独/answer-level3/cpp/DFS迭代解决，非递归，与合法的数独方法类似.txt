与上一题的检测是否合法的方法类似，建立3个vector里用bitset<9>，一行一个bitset，一列一个，一个方块一个，总共9*3个，使用下标访问，是常数时间复杂度，但是开始时先用两次循环对这几个进行初始化，话不多说上代码

```
class Solution {
 public:
  void solveSudoku(vector<vector<char>> &board) {
    vector<bitset<9>> a(9);    //行
    vector<bitset<9>> b(9);    //列
    vector<bitset<9>> box(9);  // box
    stack<pair<int, int>> pos;
    char cnum;
    int num;
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        cnum = board[i][j];
        num = cnum - '0' - 1;
        if (cnum != '.')
          a[i][num] = b[j][num] = box[i / 3 * 3 + j / 3][num] = 1;
      }
    }
    for (int i = 0, j = 0;;) {
      if (board[i][j] == '.') {
        for (int n = 1; n <= 10; ++n) {
          if (n <= 9 &&
              !(a[i][n - 1] | b[j][n - 1] | box[i / 3 * 3 + j / 3][n - 1])) {
            pos.push(make_pair(i, j));
            a[i][n - 1] = b[j][n - 1] = box[i / 3 * 3 + j / 3][n - 1] = 1;
            board[i][j] = n + '0';
            ++j;
            break;
          } else if (n >= 9) {
            auto t = pos.top();
            i = t.first;
            j = t.second;
            n = board[i][j] - '0';
            a[i][n - 1] = b[j][n - 1] = box[i / 3 * 3 + j / 3][n - 1] = 0;
            board[i][j] = '.';
            pos.pop();
          }
        }
      } else
        ++j;
      if (j == 9) {
        if (++i == 9) return;
        j = 0;
      }
    }
    return;
  }
};
```
还写了一个c语言递归的写法，不是很快，还在思考如何不用flag来保持不被回溯。。。
```
int hang[9][9];
int lie[9][9];
int cube[9][9];
bool flag;

void dfs(char **b, int r, int c, int n) {
    if (n > 9) return;
    if (r >= 9) {
        flag = 1;
        return;
    }
    if (c >= 9) {
        dfs(b, r + 1, 0, 1);
        return;
    }
    if (b[r][c] == '.') {
        if (!hang[r][n - 1] && !lie[c][n - 1] && !cube[r / 3 * 3 + c / 3][n - 1]) {
            b[r][c] = n + '0';
            hang[r][n - 1] = lie[c][n - 1] = cube[r / 3 * 3 + c / 3][n - 1] = 1;
            dfs(b, r, c + 1, 1);
            hang[r][n - 1] = lie[c][n - 1] = cube[r / 3 * 3 + c / 3][n - 1] = 0;
            if (!flag) b[r][c] = '.';
            dfs(b, r, c, n + 1);
        } else {
            dfs(b, r, c, n + 1);
        }
    } else
        dfs(b, r, c + 1, 1);
    return;
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
    *boardColSize = 9;
    char t;
    int k;
    flag = 0;
    memset(hang, 0, sizeof(hang));
    memset(lie, 0, sizeof(lie));
    memset(cube, 0, sizeof(cube));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            t = board[i][j];
            k = t - '1';
            if (t != '.') {
                hang[i][k] = 1;
                lie[j][k] = 1;
                cube[i / 3 * 3 + j / 3][k] = 1;
            }
        }
    }
    dfs(board, 0, 0, 1);
    return;
}


```
