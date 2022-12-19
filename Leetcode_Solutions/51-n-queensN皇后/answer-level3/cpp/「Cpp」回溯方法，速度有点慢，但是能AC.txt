### 解题思路

之前是 写了一个专门的函数来检查当前步骤是否可行，在函数体中分别检查列、左下角、右下角

现在用一个set，存放位置,

```cpp
    set<int> cols;
    set<int> pie;
    set<int> na;
```

通过下面这条语句来检查是否合适

```cppp
cols.count(col) > 0 || pie.count(row+col) >0 || na.count(row-col) >0
```

举个例子，初始状态set为空，

row = 0, col = 0, cols, pie, na都为0，说明这步可行，

更新cols, pie, na状态， cols = 0, pies = 0, na = 0

递归一层，row=1, 
 - col = 0, 发现不通过
 - col =1, cols通过,pie.count(1+1)通过，但是na.count(1-1)不通过
 - col= 2, cols通过 pie.count(1+2)通过，na.count(1-2)也通过
 - 更新cols, pie,na 状态 cols=(0,2), pies=(0,3), na(0,-1)
   - 递归一层 row =2
。。。

最后回来的时候，要把之前的状态还原。

最后输出结果，单独写了一个函数，根据每一层皇后的位置，输出对应的字符串数组

```cpp
    vector<string> generate_result(vector<int>& curr, int n){
        vector<string> res;
        for (int i = 0; i < curr.size(); i++){
            string tmp ;
//左边
            for (int j = 0; j < curr[i]; j++){
                tmp += ".";
            }
//皇后
            tmp += "Q";
//右边
            for (int j = curr[i]+1; j < n; j++){
                tmp += ".";
            }
            res.push_back(tmp);
        }
        return res;

    }
```

### 代码

```cpp
//51. N皇后
// https://leetcode-cn.com/problems/n-queens/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> res;
        if (n < 1) return res;

        set<int> cols;
        set<int> pie;
        set<int> na;
     
        vector<int> curr;

        DFS(n, 0, cols, pie , na, curr, res);

        return res;

    }
    void DFS(int n, int row, set<int>& cols, set<int>& pie, set<int>& na, vector<int>& curr, vector<vector<string>>& res){
        if (row >= n){
            res.push_back(generate_result(curr, n));
            return ;
        }

        for (int col = 0; col < n; col++){
            if ( cols.count(col) > 0 || pie.count(row+col) >0 || na.count(row-col) >0 ) {
                continue;
            }
            cols.insert(col);
            pie.insert(row+col);
            na.insert(row-col);

            curr.push_back(col);
            DFS(n, row+1, cols, pie, na, curr, res);
            // reverse
            curr.pop_back();
            cols.erase(col);
            pie.erase(row+col);
            na.erase(row-col);


        }

    }
    vector<string> generate_result(vector<int>& curr, int n){
        vector<string> res;
        for (int i = 0; i < curr.size(); i++){
            string tmp ;
            for (int j = 0; j < curr[i]; j++){
                tmp += ".";
            }
            tmp += "Q";
            for (int j = curr[i]+1; j < n; j++){
                tmp += ".";
            }
            res.push_back(tmp);
        }
        return res;

    }
};


```