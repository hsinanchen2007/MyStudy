```
class Solution {
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        int N = 0;
        unordered_multimap<int, pair<int, int>> jobs;
        for (int i = 0; i < startTime.size(); ++i) {
            N = max({N, startTime[i], endTime[i]});
            jobs.emplace(make_pair(endTime[i], make_pair(startTime[i], profit[i])));
        }
        vector<int> dp(N);
        for (int i = 1; i < N; ++i) {
            auto range = jobs.equal_range(i + 1);
            if (range.first == jobs.end())
                dp[i] = dp[i - 1];
            else {
                int max = 0;
                for (auto iter = range.first; iter != range.second; ++iter) {
                    if (auto v = dp[iter->second.first - 1] + iter->second.second; max < v)
                        max = v;
                }
                dp[i] = dp[i - 1] > max ? dp[i - 1] : max;
            }
        }
        return dp[N - 1];
    }
};
```
