### 解题思路
笔记：
1. 没有返回值，预先准备好的ans用于存放答案；
2. temp初始化，且每次完成递归就会把Q改回去；
3. 回溯思想体现在如果没有符合条件的col，就不再向下调用递归。

### 代码

```cpp
class Solution {
public:
    bool is_valid(vector<string> & temp, int i, int j, int n) {
        if (i==0) return true;
        int x=0;
        int y=0;
        while (x<i) {
            if (temp.at(x).at(j) == 'Q') return false;
            x++;
        }
        x=i;
        y=j;
        while (x>=0 && y>=0) {
            if (temp.at(x).at(y) == 'Q') return false;
            x--;
            y--;
        }
        x=i;
        y=j;
        while (x>=0 && y<n) {
            if (temp.at(x).at(y) == 'Q') return false;
            x--;
            y++;            
        }
        return true;
    }
    void solveNQueens_core(vector<vector<string>> & re, vector<string> & temp, int row, int n) {
        if (row == n) {
            re.push_back(temp);
            return;
        } 
        for (int j=0; j<n; j++) {
            if (is_valid(temp, row, j, n)) {
                temp[row][j] = 'Q';
                solveNQueens_core(re, temp, row+1, n);
                temp[row][j] = '.';
            }
        }
    }    
    vector<vector<string>> solveNQueens(int n) {
        //单个解
        string t;
        for (int i=0; i<n;i++) {
            t += '.';
        }
        vector<string> temp(n, t); 
        //所有解
        vector<vector<string>> re;        
        solveNQueens_core(re, temp, 0, n);
        return re;
    }
};
```