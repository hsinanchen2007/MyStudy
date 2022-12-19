### 解题思路
本解法受启发于[52. N皇后 II](https://leetcode-cn.com/problems/n-queens-ii/)：
1. 首先对整个queens数组遍历，对于与国王同行、列的皇后，记录下离国王最近的。
2. 对于与国王在两条对角线上的皇后，，利用r+l与r-l来判断，同样记录下离国王最近的。
- 时间复杂度是对queens数组的一趟遍历，O(n)。
- 空间复杂度是两个八方向的索引数组，O(1)。
这个方法很容易就可以扩展到非8x8大小的棋盘，且空间复杂度不变，需要修改的只有初始的索引值数组。
效率也还可以吧，贴个图。
![TIM截图20191204200044.jpg](https://pic.leetcode-cn.com/5f16b17ce6fffa3ea68cf39259f4c7b58e6896345f2f21fb13a093bc1ce5ca0c-TIM%E6%88%AA%E5%9B%BE20191204200044.jpg)


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> res;
        vector<int> idxes = {
            8, -1, 8, -1, 8, -1, 8, -1
        };
        vector<int> ridxes(8, -1);
        for(int i = 0; i < queens.size(); i++) {
            if(queens[i][0] == king[0]) {
                if(queens[i][1] > king[1]) {
                    if(idxes[0] > queens[i][1]) {
                        idxes[0] = queens[i][1];
                        ridxes[0] = i;
                    }
                }
                else {
                    if(idxes[1] < queens[i][1]) {
                        idxes[1] = queens[i][1];
                        ridxes[1] = i;
                    }
                }
            }
            else if(queens[i][1] == king[1]) {
                if(queens[i][0] > king[0]) {
                    if(idxes[2] > queens[i][0]) {
                        idxes[2] = queens[i][0];
                        ridxes[2] = i;
                    }
                }
                else {
                    if(idxes[3] < queens[i][0]) {
                        idxes[3] = queens[i][0];
                        ridxes[3] = i;
                    }
                }
            }
            else if(queens[i][0] + queens[i][1] == king[0] + king[1]) {
                if(queens[i][0] > king[0]) {
                    if(idxes[4] > queens[i][0]) {
                        idxes[4] = queens[i][0];
                        ridxes[4] = i;
                    }
                }
                else {
                    if(idxes[5] < queens[i][0]) {
                        idxes[5] = queens[i][0];
                        ridxes[5] = i;
                    }
                }
            }
            else if(queens[i][0] - queens[i][1] == king[0] - king[1]) {
                if(queens[i][0] > king[0]) {
                    if(idxes[6] > queens[i][0]) {
                        idxes[6] = queens[i][0];
                        ridxes[6] = i;
                    }
                }
                else {
                    if(idxes[7] < queens[i][0]) {
                        idxes[7] = queens[i][0];
                        ridxes[7] = i;
                    }
                }
            }
        }

        for(int i:ridxes) {
            if(i >= 0) {
                res.push_back(queens[i]);
            }
        }

        return res;
    }
};
```