多维背包，将0、1都当做一种容量，套用01背包的解法就行了

```
class Solution {
public:
    typedef pair<int, int> item;
    item findCount(string str) {
        int zeroCount = 0, oneCount = 0;
        for (auto ch : str) {
            if (ch == '0') {
                zeroCount++;
            } else {
                oneCount++;
            }
        }
        return item(zeroCount, oneCount);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        long size = strs.size();
        vector<vector<int>> dp = vector<vector<int>>();
        for (int i=0; i<=m; i++) {
            dp.emplace_back(vector<int>(n+1, 0));
        }

        for (int i=0; i<size; i++) {
            string str = strs[i];
            auto it = findCount(str);
            int zeroCount = it.first;
            int oneCount = it.second;
            for (int j = m; j>=zeroCount; j--) {
                for (int k = n; k>=oneCount; k--) {
                    dp[j][k] = max(dp[j][k], dp[j-zeroCount][k-oneCount]+1);
                }
            }
        }
        return dp[m][n];
    }
};
```