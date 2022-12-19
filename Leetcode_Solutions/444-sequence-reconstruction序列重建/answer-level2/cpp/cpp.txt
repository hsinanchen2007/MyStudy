
```cpp
class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<int> rank(n + 1);
        for (int i = 0; i < n; i++) {
            rank[org[i]] = i;
        }
        vector<bool> succ(n + 1, false);
        vector<bool> found(n + 1, false);
        for (auto& seq : seqs) {
            if (seq.empty()) {
                continue;
            }
            register int k = seq[0];
            if (k <= 0 || k > n) {
                return false;
            }
            found[k] = true;
            for (int i = 1; i < seq.size(); i++) {
                register int l = seq[i];
                if (l <= 0 || l > n || rank[k] >= rank[l]) {
                    return false;
                }
                found[l] = true;
                if (rank[k] + 1 == rank[l]) {
                    succ[k] = true;
                }
                k = l;
            }
        }
        succ[org[n - 1]] = true;
        for (int i = 1; i <= n; i++) {
            if (!found[i] || !succ[i]) {
                return false;
            }
        }
        return true;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```