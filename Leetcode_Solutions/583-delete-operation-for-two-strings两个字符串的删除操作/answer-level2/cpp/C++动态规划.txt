C++的动态规划版本，这里只能删除，所以状态转移方程为：
fstats[i][j] = min(fstat[i - 1][j], fstatus[i][j - 1]) + 1
当word1[i - 1] == word2[j - 1]时，状态转移方程为：
fstatus[i][j] = fstatus[i - 1][j - 1]
代码如下所示，挺直白的代码。
```
class Solution {
public:
    int minDistance(string word1, string word2) {

        vector<vector<int>> fstatus(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        // init.
        for (int i = 0; i < fstatus.size(); ++i) {
            fstatus[i][0] = i;
        }
        for (int j = 0; j < fstatus[0].size(); ++j) {
            fstatus[0][j] = j;
        }

        // dp.
        for (int i = 1; i < fstatus.size(); ++i) {
            for (int j = 1; j < fstatus[0].size(); ++j) {
                fstatus[i][j] = min(fstatus[i - 1][j], fstatus[i][j - 1]) + 1;
                if (word1[i - 1] == word2[j - 1]) {
                    fstatus[i][j] = min(fstatus[i][j], fstatus[i - 1][j - 1]);
                }
            }
        }

        return fstatus.back().back();
    }
};
```
