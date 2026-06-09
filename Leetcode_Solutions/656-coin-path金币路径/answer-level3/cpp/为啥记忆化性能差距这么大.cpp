```
class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        int n = A.size();
        if (A[0] == -1 || A[n - 1] == -1) {
            return {};
        }
        vector<int> res;
        vector<int> ans{1};
        vector<int> memo(n, 0);
        vector<int> memoc(n, 0);
        int cost = 0;
        int mincost = INT_MAX;
        function<int(int)> dfs = [&](int pos)->int{
            cost += A[pos];
            if (pos == n - 1) {
                if (cost < mincost) {
                    mincost = cost;
                    res = ans;
                }
                cost -= A[n - 1];
                return A[n - 1];
            }
            if (memo[pos]) {
                if (memoc[pos] + cost - A[pos] < mincost) {
                    ans.push_back(memo[pos] + 1);
                    dfs(memo[pos]);
                    ans.pop_back();
                }
                cost -= A[pos];
                return memoc[pos] + A[pos];
            }
            int curcost = INT_MAX;
            for (int i = pos + 1; i < n && i <= pos + B; i++) {
                if (A[i] == -1) continue;
                ans.push_back(i + 1);
                int r = dfs(i);
                if (r < curcost) {
                    memo[pos] = i;
                    curcost = r;
                }
                ans.pop_back();
            }
            memoc[pos] = curcost;
            cost -= A[pos];
            return curcost < INT_MAX ? memoc[pos] + A[pos] : INT_MAX;
        };
        dfs(0);
        return res;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```
