```
typedef long long ll;
typedef pair<int, int> state;
const int MOD = 1e9+7;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<state> states(n);
        priority_queue<int, vector<int>, greater<int>> pq;
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            states[i] = state(efficiency[i], speed[i]);
        }
        sort(states.begin(), states.end(), [](state a, state b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second > b.second;
            }
        });
        ll ret = 0;
        for (int i = 0; i < n; i++) {
            ret = max(ret, states[i].first * (cur+states[i].second));
            if (pq.size() < k-1) {
                pq.push(states[i].second);
                cur += states[i].second;
            }
            else if (!pq.empty() && states[i].second > pq.top()) {
                cur -= pq.top();
                pq.pop();
                pq.push(states[i].second);
                cur += states[i].second;
            }
        }
        return ret % MOD;

        
    }
};
```
