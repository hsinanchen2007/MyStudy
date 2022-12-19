### 解题思路
1、未投其他人
2、被每个人投
由1、2可以得出-》法官投票数+被投票数 == N - 1
### 代码

```cpp
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int graph[N];
        memset(graph, 0, N * sizeof(int));
        for (auto &var : trust) {
            graph[var[1] - 1]++;    // 被投
            graph[var[0] - 1]--;    // 投
        }

        for (int i = 0; i < N; i++) {
            if (graph[i] == N - 1) {
                return i + 1;
            }
        }

        return -1;
    }
};
```