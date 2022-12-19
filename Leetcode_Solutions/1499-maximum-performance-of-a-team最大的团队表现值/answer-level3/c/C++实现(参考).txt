```c
class Solution {
public:
    using pll = pair<long long, long long>;
    const long long MOD = 1e9+7;

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pll> members;
        priority_queue<int, vector<int>, greater<int>> group;
        for (int i = 0; i < n; i ++ ) 
            members.push_back({speed[i], efficiency[i]});
        sort(members.begin(), members.end(), 
            [](const pll& p1, const pll& p2) -> bool {
                return p1.second > p2.second; 
            }
        );

        long long maxSum = 0, sum = 0;

        for (int i = 0; i < members.size(); i ++ ) {
            group.push(members[i].first);
            sum += members[i].first;
            if (group.size() > k) {
                sum -= group.top();
                group.pop();
            }
            maxSum = max(maxSum, sum * members[i].second);
        }

        return maxSum % MOD;
    }
};
```