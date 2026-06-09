```
class Solution {
public:
    int bestRotation(vector<int>& A) {
        int N = A.size();
        vector<int> mark(N, 0);
        for (int i = 0; i < N; ++i) {
            int k_in = (i + 1) % N; // 得分区间入口
            int k_out = (N + i + 1 - A[i]) % N; // 得分区间出口
            ++mark[k_in];
            --mark[k_out];
        }
        int res = 0;
        int score = 0;
        int max_score = INT_MIN;
        for (int i = 0; i < N; ++i) {
            score += mark[i]; // 寻找最大累计和，也就是最大重合区间数目
            if (score > max_score) {
                res = i;
                max_score = score;
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/44ce6c10857b6e50aa3c784f3632e3360b6a42af8217650da29c6bb0ebd80448-image.png)
