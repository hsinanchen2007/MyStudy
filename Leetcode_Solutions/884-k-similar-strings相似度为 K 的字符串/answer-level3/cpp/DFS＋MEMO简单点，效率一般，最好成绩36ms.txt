```
class Solution {
public:
    int kSimilarity(string A, string B) {
        int n = A.size();
        unordered_map<string, int> memo{{B, 0}};
        function<int(string&, int)> dfs = [n, &memo, &dfs, &B](string& A, int i)->int{
            while (i < n && A[i] == B[i]) i++;
            int cnt = n - i;
            for (int j = i + 1; j < n; j++) {
                if (A[j] != B[i] || A[j] == B[j]) continue;
                swap(A[i], A[j]);
                cnt = min(cnt, 1 + (memo.count(A) ? memo[A] : memo[A] = dfs(A, i + 1)));
                swap(A[i], A[j]);
            }
            return cnt;
        };
        return dfs(A, 0);
    }
};
```
