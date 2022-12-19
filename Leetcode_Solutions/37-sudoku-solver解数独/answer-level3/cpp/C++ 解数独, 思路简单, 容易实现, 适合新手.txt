直观来讲,数独问题就是在空中填入数, 并且满足约束条件.
如果说在当前空中没有一个数满足约束条件, 肯定是之前的空填错了,那么就需要回溯.
整个思路按照回溯算法进行, 也就是说在深度搜索的过程中, 需要记录每一步填入数的过程.

所以算法如下:
1. 找到当前棋盘下的第一个空, 填入满足约束条件的数,入栈
2. 迭代第1步, 直到出现当前空中没有一个数满足约束条件的情况, 弹栈
3. 在上一步填入下一个数, 循环第1,2步
4. 没有空可以填入数,则结束
```
void print(vector<pair<int, int>> vec) {
    for (auto a : vec) {
        cout << a.first << ' ' << a.second<<" | ";
    }
    cout << endl;
}

template<typename T>
void print(vector<T> vec) {
    for (auto a : vec) {
        cout << a << ' ';
    }
    cout << endl;
}

template<typename T>
void print(vector<vector<T>> vec) {
    for (const auto &v: vec) {
        print(v);
    }
    cout << endl;
}

class Solution {
public:
    using Point = pair<int, int>;

    bool check(int row, int col, char value, vector<vector<char>> &board) {
        int grid_row = row / 3;
        int grid_col = col / 3;
        for (int i = grid_row * 3; i < (grid_row + 1) * 3; i++) {
            for (int j = grid_col * 3; j < (grid_col + 1) * 3; j++) {
                if (value == board[i][j])
                    return false;
            }
        }

        for (int i = 0; i < 9; i++) {
            if (value == board[i][col])
                return false;
        }

        for (int j = 0; j < 9; j++) {
            if (value == board[row][j])
                return false;
        }
        return true;
    }

    Point getNext(int row, int col, vector<vector<char>> &board) {
        Point next = {-1, -1};
        if (row != 9 && col != 9) {
            for (int j = col; j < 9; j++) {
                if (board[row][j] == '.') return make_pair(row, j);
            }
            for (int i = row + 1; i < 9; i++)
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == '.') return make_pair(i, j);
                }
        }
        return next;
    }

    bool dfs(int row, int col, vector<vector<char>> &board, vector<Point> &stack) {
        auto p = getNext(row, col, board);
        if (p.first == -1) {
            return true;
        }
        bool is_check = false;
        for (char c = '1'; c <= '9'; c++) {
            if (check(p.first, p.second, c, board)) {
                board[p.first][p.second] = c;
                stack.emplace_back(p.first, p.second);
                print(stack);
                print<char>(board);
                if (p.second + 1 == 9) {
                    is_check = dfs(p.first + 1, 0, board, stack);
                } else {
                    is_check = dfs(p.first, p.second + 1, board, stack);
                }
            }
        }
        // 运行到这里, 就会出现没有一个数可以填入当前空, 弹栈
        if (!is_check) {
            auto g = stack[stack.size() - 1];
            stack.pop_back();
            board[g.first][g.second] = '.';
        }
        return is_check;
    }

    vector<vector<char>> solveSudoku(vector<vector<char>> &board) {
        vector<Point> stack;
        dfs(0, 0, board, stack);
//        print<char>(board);
        return board;
    }
};
```