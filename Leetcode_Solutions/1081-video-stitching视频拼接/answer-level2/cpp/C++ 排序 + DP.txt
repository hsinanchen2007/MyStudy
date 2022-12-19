```
// 排序 + 贪心
class Solution {
public:
    static int cmp(const vector<int>& v1, const vector<int>& v2) {
        if (v1[0] == v2[0]) return v1[1] > v2[1];
        return v1[0] < v2[0];
    }
    int videoStitching(vector<vector<int>>& clips, int T) {
        if (T == 0) return 0;
        if (clips.empty()) -1;
        sort(clips.begin(), clips.end(), cmp);
        if (clips[0][0] > 0) return -1;
        int r = clips[0][1];
        if (r >= T) return 1;
        int res = 1;
        int i = 1;
        int N = clips.size();
        while (i < N) {
            int t = r;
            while (i < N && clips[i][0] <= t) {
                r = max(r, clips[i][1]);
                ++i;
            }
            if (r == t) return -1;
            ++res;
            if (r >= T) return res;
        }
        return -1;
    }
};
```
![image.png](https://pic.leetcode-cn.com/c33a874e91bc6149e89d0fdff280804ae7811dad887c20dd0449d76ceb44e493-image.png)

```
// DP
class Solution {
public:
    const int INF = 100000000;
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        if (clips[0][0] > 0) return -1;
        vector<int> dp(T + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= T; ++i) {
            for (auto& v : clips) {
                if (v[0] < i && v[1] >= i) {
                    dp[i] = min(dp[i], dp[v[0]] + 1);
                }
            }
        }
        return (dp[T] == INF) ? -1 : dp[T];
    }
};
```
![image.png](https://pic.leetcode-cn.com/e7a2868c94a93480047a24f21cbbf7b7a0a56db642a901132c61769423230297-image.png)
