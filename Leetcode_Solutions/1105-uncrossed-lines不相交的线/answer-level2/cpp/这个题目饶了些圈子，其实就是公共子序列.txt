AC代码如下
```
#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <limits>
#include <algorithm>
#include <memory.h>

using namespace std;





class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int dp[A.size()+1][B.size()+1];
        for (int i = 0; i <= A.size(); ++i) {
            fill(dp[i], dp[i] + B.size()+1, 0);
        }
        for (int i = 1; i <= A.size(); ++i) {
            for (int j = 1; j <= B.size(); ++j) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                }
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                dp[i][j] = max(dp[i][j-1], dp[i][j]);
            }
        }
        return dp[A.size()][B.size()];
    }
};
```