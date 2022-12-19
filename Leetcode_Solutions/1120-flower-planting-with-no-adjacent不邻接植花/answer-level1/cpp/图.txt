### 解题思路
执行用时 :120 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :34.3 MB, 在所有 C++ 提交中击败了86.40%的用户

1、可以简单构造图标识相同的花园，但内存空间超限
2、采用vector<vector<int>>结构标识所有的联通信息

### 代码

```cpp
class Solution {
public:
        const vector<int> color = {1, 2, 3, 4};
        void VoteColor(const vector<int> &connIndex, vector<int> &result, int gardenIndex) {
            // 找到不可选的颜色列表
            int rejectColor[] = {0, 0, 0, 0};
            for (int i : connIndex) {
                if (result[i] != -1) {
                    rejectColor[result[i] - 1] = 1;
                }
            }

            // 使用第一个可以用的颜色
            for (int i = 0; i < 4; i++) {
                if (rejectColor[i] == 0) {
                    result[gardenIndex] = color[i];
                    return;
                }
            }
        }

        vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
            vector<int> result(N, -1);
            vector<vector<int>> graph(N,vector<int>());

            for (auto &var : paths) {
                graph[var[1] - 1].push_back(var[0] - 1);
                graph[var[0] - 1].push_back(var[1] - 1);
            }

            for (int i = 0; i < N; i++) {
                VoteColor(graph[i], result, i);
            }

            return result;
        }
};
```