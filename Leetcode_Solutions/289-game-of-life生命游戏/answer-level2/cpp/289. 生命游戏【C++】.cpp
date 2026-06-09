### 解题思路

这个题目难度不大，思路很容易想到，只要直到每个格子的当前状态和它周围活细胞（知道周围活细胞的个数等同于知道周围死细胞的个数）的个数，就可以知道它的下一个状态。

需要知道的数据有两个：**当前状态**和**周围活细胞的个数**。很容易想到再建一个等大的二维数组来保存对应位置上的细胞周围的活细胞的个数，所以很顺畅的写出了第一份代码（代码一）。

其实题目的“进阶”部分也提到了，这个题是可以用原地算法解的，也就是不用另外创建二维数组来保存每个格子周围的活细胞数量。

思考了一下，如果要直接在原二维数组上做修改，那么每一个位置相当于要同时保存**当前状态**和**周围活细胞的个数**两条信息，于是通过 *观察法* 发现每个格子就两种状态要么1要么0，可以把它等价的转换为要么**为正**要么**为负**，这样就可以把活细胞周围的活细胞个数用正数表示，而死细胞周围的活细胞个数用负数表示。开始撸代码，然后会发现，如果周围活细胞的个数为0，那么当前细胞不管是活细胞还是死细胞都保存为了0，这就导致这种情况下无法正确判断当前格子的下一个状态。解决办法很简单，不管正负，把个数都+1。（例如，若当前格子是活细胞，周围有4个活细胞，则将当前格子置为5；若当前格子是死细胞，周围活细胞个数为2，则将当前格子置为-3）

### 代码

- **代码一：**另外创建一个等大二维数组保存每个格子周围的活细胞个数
```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> sta;//记录每个坐标周围有多少个活细胞
        const vector<pair<int, int>> dir = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
        for (int i = 0; i < board.size(); i++) {
            vector<int> s;
            for (int j = 0; j < board[0].size(); j++) {
                int num = 0;//周围活细胞个数
                for (auto d : dir) {
                    int ii = i + d.first;
                    int jj = j + d.second;
                    if (ii >= 0 && ii < board.size() && jj >= 0 && jj < board[0].size() && board[ii][jj] == 1)
                        num++;
                }
                s.push_back(num);
            }
            sta.push_back(s);
        }
        //一次更新
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 1) {
                    if (sta[i][j] < 2 || sta[i][j] >3)
                        board[i][j] = 0;
                }
                if (board[i][j] == 0 && sta[i][j] == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};
```

- **代码二：**在原表上修改，不需要额外创建数组
```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const vector<pair<int, int>> dir = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                //活细胞用正数保存其周围活细胞的个数+1，死细胞用负数保存周围活细胞的个数+1
                board[i][j] = board[i][j] == 0 ? -1 : 1;
                for (auto d : dir) {
                    int ii = i + d.first;
                    int jj = j + d.second;
                    if (ii >= 0 && ii < board.size() && jj >= 0 && jj < board[0].size() && board[ii][jj] > 0) {
                        if (board[i][j] > 0)
                            board[i][j]++;
                        else board[i][j]--;
                    }
                }
            }
        }
        //一次更新
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] > 0) {
                    if (board[i][j] - 1 < 2 || board[i][j] - 1 > 3) {
                        board[i][j] = 0;
                    }
                    else board[i][j] = 1;
                }
                if (board[i][j] < 0) {
                    if (abs(board[i][j] + 1) == 3)
                        board[i][j] = 1;
                    else board[i][j] = 0;
                }
            }
        }
    }
};
```