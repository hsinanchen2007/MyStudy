```java []
class Solution {
    // 定义每个点可移动的4个方向
    private int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    // private int[][] board;
    // 使用状态压缩算法->使用字符串进行状态压缩
    // 转化为最短路径问题-->使用BFS算法求解    
    public int slidingPuzzle(int[][] board) {
        // this.board = board;
        // BFS辅助队列
        Queue<String> queue = new LinkedList<>();
        // 使用HashMap存储操作步骤和异动步数
        HashMap<String, Integer> visited = new HashMap<>();

        // 初始化盘面, 将数组盘面转为字符串状态
        String initalBoard = boardToString(board);
        // 判断初始状态
        if(initalBoard.equals("123450"))
            return 0;

        // 进行BFS搜索
        queue.add(initalBoard);
        visited.put(initalBoard, 0);

        while(!queue.isEmpty()){
            String cur = queue.remove();
            // 得到当前状态的下一步可能状态
            ArrayList<String> nexts = getNext(cur);

            // 对下一步可能的状态进行遍历
            for(String next: nexts){
                if(!visited.containsKey(next)){
                    queue.add(next);
                    visited.put(next, visited.get(cur)+1);

                    // 判断是否达到终止状态
                    if(next.equals("123450"))
                        return visited.get(next);
                }
            }
        }

        return -1;
    }

    // 下一步状态
    private ArrayList<String> getNext(String cur){
        int[][] board = stringToBoard(cur);
        // 找到可移动格子:0的位置
        int zero = 0;
        for(zero=0; zero<6; ++zero)
            if(board[zero/3][zero%3]==0)
                break;
        int x = zero/3;
        int y = zero%3;

        ArrayList<String> res = new ArrayList<>();
        for(int []d: dirs){
            int new_x = x+d[0];
            int new_y = y+d[1];

            if(inArea(new_x, new_y)){
                swap(board, x, y, new_x, new_y);
                res.add(boardToString(board));
                swap(board, x, y, new_x, new_y);
            }
        }

        return res;
    }

    // 状态压缩，将盘面数组转为字符串
    private String boardToString(int [][]board){
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<board.length; ++i)
            for(int j=0; j<board[0].length; ++j)
                sb.append(board[i][j]);
        return sb.toString();    
    }

    // 状态解压，将字符串还原为盘面
    private int[][] stringToBoard(String str){
        int [][]board = new int[2][3];
        for(int i=0; i<str.length(); ++i){
            int x = i/3;
            int y = i%3;
            board[x][y] = str.charAt(i)-'0';
        }
        return board;
    }

    // 交换盘面数字
    private void swap(int[][] board, int x1, int y1, int x2, int y2){
        int tmp = board[x1][y1];
        board[x1][y1] = board[x2][y2];
        board[x2][y2] = tmp;
    }

    // 判断坐标是否合法
    private boolean inArea(int x, int y){
        return 0<=x && x<2 && 0<=y && y<3;
    }
}
```
```python []
from collections import deque
import operator
class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        # 代码写法参考了官方题解
        R, C = len(board), len(board[0])
        # 状态压缩转化盘面数据, 二维->一维
        start = tuple(itertools.chain(*board))
        # 建立bfs辅助队列, 存储tuple(一维盘面, 0的位置, 操作步数)
        queue = deque([(start, start.index(0), 0)])
        # 存储已访问的状态
        visited = {start}
        # 设置终止目标
        target = tuple([*range(1, R*C)]+[0])
        
        while queue:
            board, posn, depth = queue.popleft()
            if operator.eq(board, target):
                return depth
            # 一维盘面进行遍历的四个方向为(-1, 1, -C, C)
            for d in (-1, 1, -C, C):
                nex = posn+d;
                # 确保顶点的合法性(在盘面上)
                if abs(nex//C-posn//C)+abs(nex%C-posn%C) != 1:
                    continue
                if 0<= nex < R*C:
                    nex_board = list(board)
                    # 交换位置/移动方格
                    nex_board[posn], nex_board[nex] = nex_board[nex], nex_board[posn]
                    nex_board = tuple(nex_board)
                    if nex_board not in visited:
                        visited.add(nex_board)
                        queue.append([nex_board, nex, depth+1])
        return -1
```
```c++ []
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<string> q;
        unordered_map<string, int> map;
        
        string initBoard = boardToString(board);
        
        if(initBoard == "123450")
            return 0;
        
        // 使用BFS搜索最短路径
        q.push(initBoard);
        map.insert(pair<string, int>(initBoard, 0));

        while(!q.empty()){
            string cur = q.front();
            q.pop();
            
            // 得到下一步可能状态
            vector<string> nexts = getNexts(cur);
            for(auto next : nexts){
                // 如果查找到新状态, 进行访问
                if(map.find(next)==map.end()){
                    q.push(next);
                    int cur_step = map.find(cur)->second; 
                    map.insert(pair<string, int>(next, cur_step+1));

                    // 判断是否到达终点
                    if(next == "123450")
                        return cur_step+1;
                }
            }
        }
        return -1;
    }

private:
    // 得到下一步可能的状态
    vector<string> getNexts(string cur){
        vector<vector<int>> board = stringToBoard(cur);
        
        // 定位0格的位置
        int zero;
        for(zero=0; zero<6; ++zero){
            if(board[zero/3][zero%3]==0)
                break;
        }

        int x = zero/3;
        int y = zero%3;
        vector<string> res;
        for(auto d: dirs){
            int new_x = x+d[0];
            int new_y = y+d[1];

            if(inArea(new_x, new_y)){
                swap(board, x, y, new_x, new_y);
                res.push_back(boardToString(board));
                swap(board, x, y, new_x, new_y);
            }
        }
        return res;
    }

    // 状态压缩: 盘面数字转为字符串存储
    string boardToString(vector<vector<int>>& board){
        string str;
        for(int i=0; i<6; ++i){
            str += (board[i/3][i%3]+'0');
        }
        return str;
    }

    // 状态解压：字符串转为盘面数字
    vector<vector<int>> stringToBoard(string str){
        vector<vector<int>> res{2, vector<int>(3, -1)};
        for(int i=0; i<6; ++i){
            res[i/3][i%3] = str[i]-'0';
        }
        return res;
    }

    // 盘面数字移动
    void swap(vector<vector<int>> &board, int x1, int y1, int x2, int y2){
        int t = board[x1][y1];
        board[x1][y1] = board[x2][y2];
        board[x2][y2] = t;
    }

    // 判断坐标合法性
    bool inArea(int x, int y){
        return 0<=x && x<2 && 0<=y && y<3;
    }

private:
    vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};
```
