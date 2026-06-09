### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> myVecVec;

bool isValid(int row, int column, vector<string>& paths){
    for (int i = 0; i < paths[0].size(); ++i) {
        if(paths[row][i] == 'Q'){
            return false;
        }
        if(paths[i][column] == 'Q'){
            return false;
        }
    }
    for (int i = row - 1, j = column - 1;
         i >= 0 && j >= 0 ; i--, j--) {
        if (paths[i][j] == 'Q')
            return false;
    }

    for (int i = row + 1, j = column - 1;
         i < paths.size() && j >= 0; i++, j--) {
        if (paths[i][j] == 'Q')
            return false;
    }
    return true;
}
void helper(int left, int right, vector<string>& paths){
    if(left == right){
        myVecVec.push_back(paths);
        return;
    }

    for (int i = 0; i < right; ++i) {
        if(isValid(i, left, paths)){
            paths[i][left] = 'Q';

            helper(left + 1, right, paths);
            paths[i][left] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    myVecVec.reserve(n);
    vector<string> paths;

    string tmp;
    for (int j = 0; j < n; ++j) {
        tmp += ".";
    }
    for (int j = 0; j < n; ++j) {
        paths.push_back(tmp);
    }

    helper(0, n, paths);
    return myVecVec;
}
};
```