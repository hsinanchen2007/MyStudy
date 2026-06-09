### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<int> ege[N + 1];
        int ing[N + 1];
        memset(ing, 0, sizeof(ing));

        for (auto r : relations) {
            int src = r[0];
            int dst = r[1];
            ege[src].push_back(dst);
            ing[dst]++;
        }   

        queue<int> vis;
        for (int i = 1; i < N + 1; i++) {
            if (ing[i] == 0) {
                vis.push(i);
            }
        }

        if (vis.empty()) {
            return -1;
        }

        int output = 0;
        queue<int> cur_vis;
        int cnt = 0;
        while (!vis.empty()) {
            int x = vis.front();
            vis.pop();
            cnt++;
            for (auto y : ege[x]) {
                ing[y]--;
                if (ing[y] == 0) {
                    cur_vis.push(y);
                }
            }

            if (vis.empty()) {
                while (!cur_vis.empty()) {
                    vis.push(cur_vis.front());
                    cur_vis.pop();
                }
                output++;
            }
        };
        return (cnt == N) ? output : -1;
    }
};
```