### 解题思路

1. 要求最少操作次数，所以应该BFS；
2. 如果不对相同元素预处理保存在哈希表，最后一个用例会超时；
3. 哈希表全部值都入队后应该移除相应的key。

### 代码

```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        queue<pair<int, int>> Q;
        vector<bool> visited(n);
        unordered_map<int, deque<int>> dict;
        for(int i=0; i<n; i++) {
            dict[arr[i]].push_back(i);                          // 不对相同元素预处理会超时
        }
        
        Q.emplace(0, 0);
        while(!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            visited[cur.first] = true;
            if(cur.first == n - 1)
                return cur.second;
            if(cur.first + 1 < n && !visited[cur.first+1])
                Q.emplace(cur.first + 1, cur.second + 1);
            if(cur.first - 1 >= 0 && !visited[cur.first-1])
                Q.emplace(cur.first - 1, cur.second + 1);

            if(dict.count(arr[cur.first]) > 0) {
                for(int i : dict[arr[cur.first]]) {
                    if(i != cur.first && !visited[i]) {
                        Q.emplace(i, cur.second + 1);
                    }
                }
                dict.erase(arr[cur.first]);                     // 不加这一行会超时
            }
            
        }
        return -1;
    }
};
```