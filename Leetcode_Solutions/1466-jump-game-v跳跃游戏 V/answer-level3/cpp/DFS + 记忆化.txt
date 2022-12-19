### 解题思路

向左右两个方向进行DFS搜索，满足下列条件的位置：

1. 索引在 [i - d, i + d]之间；
2. 从i出发连续下降；
3. 如果记忆化数组已保存，直接返回。

### 代码

```cpp
class Solution {
private:
    vector<int> dp;
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        dp.resize(n);
        path.resize(n);
        fill(dp.begin(), dp.end(), -1);
        int maxJ = 0;
        for(int i=0; i<n; i++) {
            int cur = maxOneJump(arr, d, i);
            maxJ = max(maxJ, cur);
        }
        return maxJ;
    }
    
    int maxOneJump(vector<int>& arr, int d, int i) {
        if(dp[i] > 0)
            return dp[i];
        dp[i] = 1;
        int n = arr.size();
        int maxDis = 1;

        int j = i - 1;
        while(j >= max(0, i - d) && arr[j] < arr[i])
            j--;
        for(int k=j+1; k<=i-1; k++)
            maxDis = max(maxDis, maxOneJump(arr, d, k) + 1);

        j = i + 1;
        while(j <= min(i + d, n-1) && arr[j] < arr[i])
            j++;
        for(int k=i+1; k<=j-1; k++)
            maxDis = max(maxDis, maxOneJump(arr, d, k) + 1);

        return dp[i] = maxDis;
    }
};
```

执行用时 :56 ms