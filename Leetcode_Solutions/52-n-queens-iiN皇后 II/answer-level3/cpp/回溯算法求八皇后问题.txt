### 解题思路
回溯算法

### 代码

```cpp
class Solution {
public:
    int totalNQueens(int n) {
        return backTracking(n, 0, sol);
    }
private:
    int solutions = 0;   //N皇后的所有解
    vector<int> sol;   //N皇后的一个解
    int backTracking(int n, int row, vector<int>& sol){
        if(row == n){
            solutions += 1;
        }
        for(int j = 0; j < n; j++){   //对列进行循环
            sol.push_back(j);
            if(isValid(sol)){
                backTracking(n, row + 1, sol);
            }
            sol.pop_back();
        }
        return solutions;
    }
    bool isValid(vector<int>& sol){
        int row = sol.size() - 1;
        for(int i = 0; i < row; i++){   //对row以前的行进行循环
            int absColDistance = abs(sol[row] - sol[i]);   //求row行的列值与i行的列值的差的绝对值
            //判别条件1：若absColDistance == 0，则row行的列值等于i行的列值，即同列，不符合规则；
            //判别条件2：若absColDistance == (row - i)，则说明row行的所在的列与i行所在的列在同一对角线上（正对角线或反对角线）。
            if(absColDistance == 0 || absColDistance == (row - i))
                return false;
        }
        return true;
    }
};
```