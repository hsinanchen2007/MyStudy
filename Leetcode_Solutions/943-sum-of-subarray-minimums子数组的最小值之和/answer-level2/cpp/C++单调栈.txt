pair<minValue, weight>
```
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        stack<pair<int, int>> stk;
        int sum = 0, dot = 0;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < A.size(); i++) {
            int count = 1;
            while (!stk.empty() && A[i] <= stk.top().first) {
                auto top = stk.top();
                stk.pop();
                count += top.second;
                dot -= top.first * top.second;
            }
            dot += A[i] * count;
            stk.push(make_pair(A[i], count));
            sum += dot;
            sum %= MOD;
        }
        return sum;
    }
};
```
