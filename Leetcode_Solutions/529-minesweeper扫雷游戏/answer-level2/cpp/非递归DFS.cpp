我先看了他的题解写了DFS和BFS,然后写的非递归的
https://leetcode-cn.com/problems/minesweeper/solution/bfs-by-huihuiyue/
### 代码

```cpp
class Solution {
    int dx[8] = { -1, -1,  0,  1,  1,  1,  0, -1};  // 上,上右,右,下右,下,下左,左,上左 (顺时针)
    int dy[8] = {  0,  1,  1,  1,  0, -1, -1, -1};
    int m, n;  //长,宽
    struct Node
    {
        int x;
        int y;
        Node(int _x, int _y)
        {
            x = _x;
            y = _y;
        }
    };
public:
    int countMinesweeper(vector<vector<char>>& board, int x, int y)
    {//计算当前节点周围地雷数
        int count = 0;
        for(int i = 0; i < 8; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
            {
                continue;
            }
            if(board[nextX][nextY] == 'M')
            {
                count++;
            }
        }
        return count;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();
        int x = click[0], y = click[1];
        if(board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return board;
        }
        stack<Node>stk;
        stk.emplace(x, y);//stk.push(Node(x,y));
        while(!stk.empty())
        {
            Node cur = stk.top();
            bool finished = true;   //标记这个分支有没有走完

            if(board[cur.x][cur.y] == 'E')
            {
                board[cur.x][cur.y] = 'B';
                int count = countMinesweeper(board, cur.x, cur.y);
                if(count == 0)
                {//没地雷就递归
                    for(int i = 0; i < 8; i++)
                    {
                        int nextX = cur.x + dx[i];
                        int nextY = cur.y + dy[i];
                        if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
                        {
                            continue;
                        }
                        stk.emplace(nextX, nextY);
                        finished = false;
                    }
                }
                else
                {//有就不递归
                    board[cur.x][cur.y] = (char)(count + '0');
                }
            }
            if(finished == true)
            {
                stk.pop();
            }
        }
        return board;
    }
};
```