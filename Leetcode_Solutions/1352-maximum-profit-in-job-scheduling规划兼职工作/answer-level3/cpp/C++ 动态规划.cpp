根据任务结束时间进行排序
```
class Solution {
public:
    struct Job {
        int start, end, profit;
        Job(int s, int e, int p) : start(s), end(e), profit(p) {};
        bool operator < (const Job& other) const {
            if (end == other.end) {
                return start < other.start;
            }
            return end < other.end;
        }
    };
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int N = profit.size();
        vector<Job> jobs;
        for (int i = 0; i < N; ++i) {
            jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end());
        unordered_map<int, int> dp;
        for (int i = 0; i < N; ++i) {
            dp[jobs[i].end] = max(dp[jobs[i].end], jobs[i].profit);
            int j = i - 1;
            for (; j >= 0 && jobs[j].end > jobs[i].start; --j) {
                dp[jobs[i].end] = max(dp[jobs[i].end], dp[jobs[j].end]);
            }
            if (j >= 0) {
                dp[jobs[i].end] = max(dp[jobs[i].end], dp[jobs[j].end] + jobs[i].profit);
            }
        }
        return dp[jobs.back().end];
    }
};
```
执行用时 : 212 ms, 在所有 cpp 提交中击败了 60.14% 的用户
内存消耗 : 27.1 MB, 在所有 cpp 提交中击败了 100.00% 的用户