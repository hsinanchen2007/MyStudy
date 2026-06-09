### 解题思路
 - 首先对N皇后问题进行描述：棋子会攻击属于同一行的，同一列或者同一对角线上的棋子。
 - 根据上面的条件，可以得出判断棋子坐标是否合格的条件：1. 有没有同行棋子；2. 有没有同列棋子；3. **当前棋子与其他已有棋子连线的斜率是否为1或者-1.**

### 代码

```cpp
class Solution {
public:
    vector<int> used;
    int num = 0;

    int totalNQueens(int n) {
        used = vector<int>(n);
        for (int i = 0; i < n; ++i) {used[i] = -1;}

        dfs(0, n);
        return num;
    }

    void dfs(int x, int n) {
        if (x == n) { // 走到n,说明棋盘全部走通，一种解成立
            num++;
            return;
        }
        
        if (x == 0) { // 如果是第0行，什么都不用判断，直接走流程
            for (int j = 0; j < n; ++j) {
                used[x] = j;
                dfs (x + 1, n);
            }
        } else { // 普遍逻辑
            for (int j = 0; j < n; ++j) {
                bool b = true;
                for (int k = 0; k < x; ++k) { // 看第k行的已有元素是否会与当前元素产生冲突
                    if (j == used[k]) {
                        b = false; // 撞到了同一列
                        break;
                    }
                    if ( (x - k) == (j - used[k]) || (x - k) == (used[k] - j) ) {
                        b = false; // 撞到了同一列
                        break;
                    }
                }
                if (b) {
                    used[x] = j;
                    dfs (x + 1, n);
                }
            }
        }
    }

};
```
 - 上述代码的 vector<int> used，对于used[k]，k代表第几行，used[k]代表第几列。
 - 对于第k行元素，由于搜索顺序是从上到下，所以不用对大于k的行进行判断，也不需要进行恢复现场。