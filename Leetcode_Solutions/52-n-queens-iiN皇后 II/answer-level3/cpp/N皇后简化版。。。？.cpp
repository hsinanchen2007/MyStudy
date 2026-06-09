### 解题思路
这道和N皇后的思路是一样的，省去了看string的麻烦

### 代码

```cpp
class Solution {
public:
    bool is_valid(int n, int line, int col, vector<vector<int>> & mp) {
        int i=0;
        while (i<line) {
            if (mp[i][col] == 1) return false;
            i++;
        }
        i=line;
        int j=col;
        while (i>=0 && j>=0) {
            if (mp[i][j] == 1) return false;
            i--;
            j--;
        }
        i=line;
        j=col;
        while (i>=0 && j<n) {
            if (mp[i][j] == 1) return false;
            i--;
            j++;
        }        
        return true;
    }
    void totalNQueens_core(int n, int & re, vector<vector<int>> & mp, int line) {
        if (line == n) {
            re++;
            return;
        }
        for (int j=0; j<n; j++) {
            if (is_valid(n, line, j, mp)) {
                mp[line][j] = 1;
                totalNQueens_core(n, re, mp, line+1);
                mp[line][j] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        int re = 0;
        vector<int> lineda(n, 0);
        vector<vector<int>> mp(n, lineda);
        totalNQueens_core(n, re, mp, 0);
        return re;
    }
};
```