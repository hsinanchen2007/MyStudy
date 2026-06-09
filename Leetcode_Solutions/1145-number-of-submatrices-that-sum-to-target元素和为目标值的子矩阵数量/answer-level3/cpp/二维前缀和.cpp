### 解题思路

有一个特例，就是 `target == sum - target` 的情况。

### 代码

```cpp
class Solution {
private:
    vector<vector<int>> prefixSum;
    int m;  // row
    int n;  // col
    int count = 0;
    unordered_map<int, int> dict;
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        m = matrix.size();
        if(m == 0)
            return 0;
        n = matrix[0].size();
        prefixSum.resize(m+1, vector<int>(n+1));
        
        // 二维前缀和
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++) {
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + matrix[i-1][j-1];
            }
        
        
        for(int r1=1; r1<=m; r1++) {
            for(int r2=r1; r2<=m; r2++) {
                dict.clear();
                for(int k=1; k<=n; k++) {
                    int sum = prefixSum[r2][k] - prefixSum[r1-1][k];
                    // cout << r1 << r2 << k << sum << endl;
                    if(sum == target)
                        count++;
                    if(dict.count(sum - target) > 0)
                        count += dict[sum-target];
                    dict[sum]++;
                }
            }
        }
        
        return count;
    }
};
```