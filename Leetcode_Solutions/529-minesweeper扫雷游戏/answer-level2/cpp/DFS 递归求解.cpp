### 解题思路
此处撰写解题思路
1、按题意以当前点为基准，求解上、下、左、右、左上、左下、右上、右下共8个方向
2、根据8个方向有没有M，来决定当前点的值是B还是M的数量
3、递归求解8个方向的数据
结束条件：
     访问到了边界行列之外，返回；
     访问的当前点不是E，返回；
     周边访问到了M，返回

### 代码

```cpp
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)    {
        // 容错处理 
        if (board.empty() || click.empty() || click.size() != 2) {
            return board;
        }

        int startX = click[0];
        int startY = click[1];

        int row = board.size() - 1;
        int col = board[0].size() - 1;

        if (!(startX <= row && startY <= col)) {
            return board;
        }
        // 
        if (board[startX][startY] == 'M') {
            board[startX][startY] = 'X';
            return board;
        }

        if (board[startX][startY] != 'E') {
            return board;
        }

        DFS(board, startX, startY);

        return board;
    }

    void DFS(vector<vector<char>>& board, int startX, int startY) 
    {
        
        int row = board.size() - 1;
        int col = board[0].size() - 1;

        if (!(startX >= 0 && startX <= row && startY >= 0 && startY <= col)) {
            return;
        }
        if (board[startX][startY] != 'E') {
            return;
        }
       // cout << "DFS called !" << endl;
        // 起点为一般情况下的处理，为'E' 
        int cnt = 0;
        char up = '0';
        if (startX - 1 >= 0) {
            up = board[startX - 1][startY];
            if (up == 'M') {
                cnt++;
            }
        }
        char down = '0';
        if (startX + 1 <= row) {
            down = board[startX + 1][startY];
            if (down == 'M') {
                cnt++;
            }
        }

        char left = '0';
        if (startY - 1 >= 0) {
            left = board[startX][startY - 1];
            if (left == 'M') {
                cnt++;
            }
        }

        char right = '0';
        if (startY + 1 <= col) {
            right = board[startX][startY + 1];
            if (right == 'M') {
                cnt++;
            }
        }

        char leftUp = '0';
        if (startX - 1 >= 0 && startY - 1 >= 0) {
            leftUp = board[startX - 1][startY - 1];
            if (leftUp == 'M') {
                cnt++;
            }
        }

        char rightUp = '0';
        if (startX - 1 >= 0 && startY + 1 <= col) {
            rightUp = board[startX - 1][startY + 1];
            if (rightUp == 'M') {
                cnt++;
            }
        }

        char leftDown = '0';
        if (startX + 1 <= row && startY - 1 >= 0) {
            leftDown = board[startX + 1][startY - 1];
            if (leftDown == 'M') {
                cnt++;
            }
        }

        char rightDown = '0';
        if (startX + 1 <= row && startY + 1 <= col) {
            rightDown = board[startX + 1][startY + 1];
            if (rightDown == 'M') {
                cnt++;
            }
        } 
       
        if (up != 'M' && down != 'M' && left != 'M' && right != 'M' &&
            leftUp != 'M' && rightUp != 'M' && leftDown != 'M' && rightDown != 'M') {
            board[startX][startY] = 'B';
        }

        if (cnt != 0) { // 如果靠近地雷，则搜索结束 
            board[startX][startY] = static_cast<char>(cnt + '0');
            return;
        }
        
        // 以该点为基准，对8个方向进行搜索 
        DFS(board, startX - 1, startY);
        DFS(board, startX + 1, startY); 
        DFS(board, startX, startY - 1); 
        DFS(board, startX, startY + 1);
        DFS(board, startX - 1, startY - 1);
        DFS(board, startX - 1, startY + 1);
        DFS(board, startX + 1, startY - 1);
        DFS(board, startX + 1, startY + 1);
    }
};
```