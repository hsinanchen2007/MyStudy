### 解题思路
state : f[i][j] a字符串的前i个字符最少要几次变成b的前j个字符；
function : Min(f[i - 1][j] + 1, f[i][j - 1] + 1, f[i - 1][j - 1])     a[i] == b[j]
           Min(f[i - 1][j] + 1, f[i][j - 1] + 1, f[i - 1][j - 1] + 1) a[i] != b[j]
初始化：
    f[i][0] = i : 把 a[i] 对应 b是（空串），所以每个位置都要补一个 a[i];
    f[0][j] = j : 把 b[j] 对应 a是（空串），所以每个位置都要补一个 b[j];
answer:
    f[a.length][b.length]

### 代码

```cpp
#include <cmath>
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() == 0) return word2.size();
        if (word2.size() == 0) return word1.size();

        vector<vector<int>> vec(word1.size() + 1, vector<int>(word2.size() + 1));
        // 初始化 [i][0]和[0][j]
        for (int i = 0; i < word1.size() + 1; i++) {
            vec[i][0] = i;
        }
        for (int j = 0; j < word2.size() + 1; j++) {
            vec[0][j] = j;
        }

        for (int i = 1; i < word1.size() + 1; i++) {
            for (int j = 1; j < word2.size() + 1; j++) {
                if(word1[i - 1] == word2[j -1 ]) { 
                    vec[i][j] = min(vec[i - 1][j - 1], min(vec[i - 1][j] + 1, vec[i][j - 1] + 1));
                } else {
                    vec[i][j] = min(vec[i - 1][j - 1] + 1, min(vec[i][j - 1] + 1, vec[i - 1][j] + 1));
                }
            }
        }
        return vec[word1.size()][word2.size()];
    }
};
```