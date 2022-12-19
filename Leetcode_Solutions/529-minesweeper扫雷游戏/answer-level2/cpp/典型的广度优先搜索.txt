#### 解题思路: ####

1. 从点击点开始(点击点只能为 `E` 或 `M`)
-  如果为`M` 则直接将当前位置修改为 `X` 返回board。
-  如果为 `E` 看`2`
2. 开始`BFS`
- 计算当前点八个方向上地雷数量, 如果 `> 0` 则修改为数量, 返回board。
- 如果为0, 则将八个方向上为 `E` 的顶点依次加入到增广队列当中。
- 依次针对队列中的每个顶点再从 `2` 开始
 
#### 小技巧: ####
1. 平面上基于当前点的下一个点位置可以根据如下代码计算, 不用写八个循环:
```C++ []
//右 -> 右下 -> 下 -> 左下 -> 左 -> 左上 -> 上 -> 右上
int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dc[8] = {1, 1, 0, -1, -1, -1, 0, 1};
for(int i = 0; i != 8; ++i)
{
    int nnr = r + dr[i], nnc = c + dc[i];
    //没有越界
    if(nnr >= 0 && nnr < rsize && nnc >= 0 && nnc < csize )
        //...TODO
}
```

#### 注意事项: ####
1. 一定要设置一个状态数组用来确定已经处理过的顶点不再进入增广队列当中。

#### 代码如下 ####
```C++ []
class Solution 
{
public:
    //右 -> 右下 -> 下 -> 左下 -> 左 -> 左上 -> 上 -> 右上
    int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dc[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int stat[50][50];                               //状态
    typedef pair<int, int> Point;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) 
    {
        int rsize = board.size(), csize = board[0].size();
        queue<Point> que;
        
        //点击到地雷
        if(board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;    
        }
        
        //初始化状态
        memset(stat, 0, sizeof(stat));
        que.push({click[0], click[1]});
        stat[click[0]][click[1]] = 1;
        
        while(!que.empty())
        {
            Point p = que.front(); que.pop();
            
            //计算相邻的地雷的数量
            int cnt = 0, r = p.first, c = p.second;
            for(int i = 0; i != 8; ++i)
            {
                int nnr = r + dr[i], nnc = c + dc[i];
                //没有越界, 并且为地雷的情况。
                if(nnr >= 0 && nnr < rsize && nnc >= 0 && nnc < csize 
                   && (board[nnr][nnc] == 'M' || board[nnr][nnc] == 'X'))
                    ++cnt;
            }
            
            // 如果有地雷, 直接揭露。
            if(cnt > 0)
                board[r][c] = cnt + '0';
            
            // 否则揭露为B, 并增广其相邻的元素
            else
            {
                board[r][c] = 'B';
                for(int i = 0; i != 8; ++i)
                {
                    int nnr = r + dr[i], nnc = c + dc[i];
                    //相邻的顶点没有越界, 并且没有被增加到增广队列当中, 且没有被翻过为E
                    if(nnr >= 0 && nnr < rsize && nnc >= 0 && nnc < csize  && stat[nnr][nnc] == 0 && board[nnr][nnc] == 'E')
                    {
                        que.push({nnr, nnc});
                        stat[nnr][nnc] = 1;
                    }
                }
            }
        }
        return board;
    }
};
```
