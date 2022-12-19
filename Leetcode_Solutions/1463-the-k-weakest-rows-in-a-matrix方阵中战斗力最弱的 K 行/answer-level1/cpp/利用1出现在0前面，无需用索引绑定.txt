这才是这道题最简单的解法吧。题目中说1出现在0前面，行号较小的在前面，就是引导我们遍历每一列，在遍历过程中就可以拼出答案了。
```cpp
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        vector<int> fullRowIndex;
        for(int j = 0; j < n; ++j) {
            for(int i = 0; i < m; ++i) {
                if(j == 0 && mat[i][j] == 0)  // i行的第一个元素就是0
                    ans.push_back(i);
                else if(j > 0 && mat[i][j] == 0 && mat[i][j-1] == 1)
                    ans.push_back(i);
                else if(j > 0 && mat[i][j] == 0 && mat[i][j-1] == 0)
                    {}
                else if(j == n - 1 && mat[i][j] == 1)
                    fullRowIndex.push_back(i);
            }
        }
        ans.insert(ans.end(), fullRowIndex.begin(), fullRowIndex.end());
        return vector<int>(ans.begin(), ans.begin() + k);
    }
};
```
