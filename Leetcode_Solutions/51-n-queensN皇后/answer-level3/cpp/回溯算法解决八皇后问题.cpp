### 解题思路
回溯法

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        backTracking(n, 0, sol, solutions);
        return solutions;
    }
private:
    vector<vector<string> > solutions;   //N皇后的所有解
    vector<int> sol;   //N皇后的一个解
    void backTracking(int n, int row, vector<int>& sol, vector<vector<string> >& solutions){
        if(row == n){
            vector<string> temp = vecNumToString(sol, n);
            solutions.push_back(temp);
        }
        for(int j = 0; j < n; j++){   //对列进行循环
            sol.push_back(j);
            if(isValid(sol)){
                backTracking(n, row + 1, sol, solutions);
            }
            sol.pop_back();
        }
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
    vector<string> vecNumToString(vector<int>& sol, int n){
        vector<string> temp;
        for(int i = 0; i < n; i++){
            string s = "";
            for(int j = 0; j < n; j++){
                if(j == sol[i])
                    s += 'Q';
                else
                    s += '.';
            }
            temp.push_back(s);
        }
        return temp;
    }
};
```