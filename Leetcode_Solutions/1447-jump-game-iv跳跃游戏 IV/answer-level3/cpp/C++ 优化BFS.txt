### 解题思路
开始用回溯+剪枝，但是到第21个用例超出内存限制；后转用BFS+queue，配合之前的优化，通过。
1. 用unordered_map<int, vector<int>>记录相同值的下标，但要优化内存，去掉单个值的记录；
2. 要么往前跳一步，要么往后跳一步，要么跳到相同值的地方；
3. 相同值位置全部入队后，删除map中对应的记录，避免重复查找；
4. 用visited数组记录访问过的位置；
![图片.png](https://pic.leetcode-cn.com/798bdbfc85962ad71c1847681ae1e024c9b8910c41a0e2431bba59cbb21d4e94-%E5%9B%BE%E7%89%87.png)


### 代码

```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> sameValue;
        for (int i = 0; i < n; ++i) {
            sameValue[arr[i]].push_back(i);
        }
        // 优化内存：去除单值记录
        for (auto it = sameValue.begin(); it != sameValue.end();) {
            if (it->second.size() == 1) {
                it = sameValue.erase(it);
            } else {
                ++it;
            }
        }

        int currStep = 0;
        vector<bool> visited(n, false);
        queue<int> q;
        visited[0] = true;
        q.push(0);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int t = q.front();
                q.pop();
                if (t == n - 1) {
                    return currStep;
                }
                // 调到相同值的位置
                if (sameValue.find(arr[t]) != sameValue.end()) {
                    auto tunnels = sameValue[arr[t]];
                    for (int tunnel : tunnels) {
                        if (tunnel == t || visited[tunnel]) {
                            continue ;
                        }
                        visited[tunnel] = true;
                        q.push(tunnel);
                    }
                    sameValue.erase(arr[t]); // 同值位置已经用完，删除以避免重复查找。
                }
                // 向前一步
                if (t + 1 < arr.size() && !visited[t + 1]) {
                    visited[t + 1] = true;
                    q.push(t + 1);
                }
                // 后退一步
                if (t - 1 >= 0 && !visited[t - 1]) {
                    visited[t - 1] = true;
                    q.push(t - 1);
                }
            }
            ++currStep;
        }
        
        // 不会走到这里
        return -1;
    }
};
```