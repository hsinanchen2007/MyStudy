没什么好说的把，杨辉三角中每个数是它左上方和右上方的数的和。

AC代码：
```
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> res(numRows);

        for (int i = 0; i < numRows; i++) {
            res[i].resize(i + 1);
            res[i][0] = res[i][i] = 1;
  
            for (int j = 1; j < i; j++)
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
        
        return res;
    }
};
```