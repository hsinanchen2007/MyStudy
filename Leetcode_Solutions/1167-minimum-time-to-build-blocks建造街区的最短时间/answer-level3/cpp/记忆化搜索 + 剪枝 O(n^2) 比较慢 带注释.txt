```cpp
class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        sort(blocks.begin(), blocks.end(), greater<int>());
        vector<vector<int>> dp(blocks.size(), vector<int>(blocks.size(), INT_MAX));
        return minBuildTime(blocks, dp, split, 1, 0);
    }

    int minBuildTime(vector<int>& blocks, vector<vector<int>>& dp, int& split, int currentWorkers, int index) {
        if (currentWorkers >= blocks.size() - index)
            return blocks[index];
        if (dp[index][currentWorkers] != INT_MAX)
            return dp[index][currentWorkers];
        int result = INT_MAX;
        for (int i = currentWorkers; i >= 1; i >>= 1) {
            // i -> 这一次分裂的个数 nSplit -> 这一次不分裂的个数
            // 由于剩下的工人数不足以完成剩下所有的任务 至少分裂 1 个 最多分裂currentWorkers个 即全部分裂
            int nSplit = currentWorkers - i;
            int tmp = max(minBuildTime(blocks, dp, split, 2 * i, index + nSplit) + split, blocks[index]);
            if (result > tmp)
                result = tmp;
            else
                break;
        }
        return dp[index][currentWorkers] = result;
    }
};
```

实际上试了下第二个递归函数在n=1000的case下也只被调用了20000多次
