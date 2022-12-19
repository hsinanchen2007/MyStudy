[[WeeklyContest 158 Q1 分割平衡字符串]C++](https://leetcode-cn.com/problems/split-a-string-in-balanced-strings/solution/weeklycontest-158-q1-fen-ge-ping-heng-zi-fu-chuan-/)
[[WeeklyContest 158 Q2 可以攻击国王的皇后]C++ 迭代](https://leetcode-cn.com/problems/queens-that-can-attack-the-king/solution/weeklycontest-158-q2-ke-yi-gong-ji-guo-wang-de-hua/)
[[WeeklyContest 158 Q3 掷骰子模拟]C++ 动态规划](https://leetcode-cn.com/problems/dice-roll-simulation/solution/weeklycontest-158-q3-zhi-tou-zi-mo-ni-c-dong-tai-g/)
[[WeeklyContest 158 Q4 最大相等频率]C++ 分类讨论](https://leetcode-cn.com/problems/maximum-equal-frequency/solution/weeklycontest-158-q4-zui-da-xiang-deng-pin-lu-c-fe/)

思路：正难则反易。从国王找可以攻击到他的皇后，即尝试八条以国王为原点的射线。

```
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> map(8, vector<int>(8,0));
        vector<vector<int>> ans;
        for(auto a: queens){
            map[a[0]][a[1]] = 1;
        }
        map[king[0]][king[1]] = 2;
        int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
        for(int d = 0; d < 8; d++){
            int curx = king[0], cury = king[1];
            while(curx < 8 && curx >=0 && cury >=0 && cury < 8 && map[curx][cury] != 1){
                curx += dx[d]; cury += dy[d];
            }
            if(curx < 8 && curx >=0 && cury >=0 && cury < 8 && map[curx][cury] == 1){
                vector<int> tmp = {curx,cury};
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
```
