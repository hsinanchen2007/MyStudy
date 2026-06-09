### 解题思路
和 第 5 题 同样的 dp 思路
用 arr[i] 表示到第 i 个字符，所需要的最小切割数，
当 (left, right) 形成了回文串时， 则 arr[right] = arr[left-1] + 1;

### 代码

```cpp
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<int> arr(n, 0);
        for(int i = 0; i<n; ++i) {
            int temp = i;
            for(int j = 0; j <=i; ++j) {
                if(s[i] == s[j] && (i-j <=2 || dp[i-1][j+1])){
                    dp[i][j] = true;
                    temp = min(temp, j == 0? 0 : 1 + arr[j-1]);
                }
            }
            arr[i] = temp;
        }
        return arr[n-1];
    }
};
```