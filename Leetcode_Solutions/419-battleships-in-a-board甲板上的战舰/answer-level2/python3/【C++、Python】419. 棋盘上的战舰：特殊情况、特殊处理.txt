### 题目背景 ###
- 题目的灵感来源于**海战棋**，所以正确的翻译应该是“棋盘上的战舰”
  - 对弈双方在各自的区域排布自己的舰队，舰队中可以包含大小不等的几类舰船，比如：驱逐舰占 $1\times2$ 个格子，巡洋舰占 $1\times3$ 个格子，战列舰占 $1\times4$ 个格子……舰船可以水平放置也可以垂直放置
  - 在不清楚对方排布情况的条件下（类似 RTS 游戏中的战争迷雾设定），双方每轮有 $3$ 次开炮的机会，落点可以在对方的区域中任意选择，每次开炮后可以知道自己是否命中目标
  - 当代表一艘船的 $N$ 个格子都被击中，则这艘船被击沉
  - 若一方击沉了对方舰队的所有舰船，则取得游戏胜利
- 如果要编程实现上述游戏，必然需要判断双方棋盘上剩余舰船数目，本题正是为了实现这个功能
***
### 解决方案 ###
#### 思路 ####
- 根据题目要求，需要在一次扫描中完成，不能使用额外空间，且不修改棋盘的值，所以需要利用特殊条件
  - 战舰的形状都是 $1 \times N$ 或 $N \times 1$ 的长方形，且战舰与战舰不会接触或相交
  - 所以在扫描过程中，只需要在遍历到某个战舰最左（右）或最上（下）的一个格子时计数，其他格子都可以跳过
  - 注意：如果网格中需要计数的区块的外轮廓可能是凹多边形，显然这种方法是错误的，应该用常规的 DFS 或 BFS
#### 演示 ####
![419.gif](https://pic.leetcode-cn.com/c2aea185a74145f5efeb1ffaba108ee7854bbdbe02d7ea7bc64f04fb1d83a183-419.gif)
#### 代码 ####
```cpp []
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int R = board.size(), C = board[0].size(), res = 0;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (board[i][j] == 'X' && 
                    (!i || board[i - 1][j] == '.') && (!j || board[i][j - 1] == '.'))
                    ++res;
        return res;
    }
};
```
```python []
class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        res = 0
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'X' and (not i or board[i - 1][j] == '.') \
                    and (not j or board[i][j - 1] == '.'):
                    res += 1
        return res
```
#### 复杂度分析 ####
- 时间复杂度 $O(R \times C)$
- 空间复杂度 $O(1)$

