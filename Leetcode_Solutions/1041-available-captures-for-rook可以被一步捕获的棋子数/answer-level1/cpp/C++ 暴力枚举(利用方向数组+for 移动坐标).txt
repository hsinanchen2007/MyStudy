先来吐槽下，感觉面试中很难遇到这种题。一般面试题都会是很有编程技巧的题目(比如链表，排序等)，或者思维题（比如动态规划，一些脑筋急转弯等），或者实现一些著名的算法(比如手撕一个LRU)。至于这个题嘛，啧啧~

再来说下思路，先暴力枚举找到 R 的位置，然后从该位置开始分别向上下左右四个方向延伸，直到达到边界，或者遇到象或卒。如下图所示：
![棋盘.png](https://pic.leetcode-cn.com/6eca1c0c2fae45750e019d1f28d9f17176d3003a3483427608da6a4722b38382-%E6%A3%8B%E7%9B%98.png)


**可以预设两个数组来表示按某个方向移动时坐标的变化量，以省去冗余的移动坐标代码。**

```
class Solution {
public:
    inline pair<int, int> getPos(const vector<vector<char>> &board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == 'R') {
                    return make_pair(i,j);
                }
            }
        }
        return make_pair(-1, -1);
    }
    int numRookCaptures(vector<vector<char>>& board) {
        auto pos = getPos(board);
        if(pos.first == -1 && pos.second == -1) {
            return 0;
        }
        int dx[] = {-1, 0, 1,  0};
        int dy[] = { 0, 1, 0, -1};
        int sum = 0;
        for(int i = 0; i < 4; i++) {
            int tx = pos.first + dx[i];
            int ty = pos.second + dy[i];
            while(0 <= tx && tx < board.size() && 0 <= ty && ty < board[tx].size()) {
                if(board[tx][ty] != '.') {
                    if(board[tx][ty] == 'p') {
                        sum ++;
                    }
                    break;
                }
                tx += dx[i];
                ty += dy[i];
            }
        }
        return sum;
    }
};
```
# 欢迎关注HelloNebula, 一个过气小公主
![qrcode_for_gh_6e5f8557b1f8_258.jpg](https://pic.leetcode-cn.com/3bced0275e80f6c7776b125d31876f31fadf978ba7b99bbc020010169c0d4320-qrcode_for_gh_6e5f8557b1f8_258.jpg)



