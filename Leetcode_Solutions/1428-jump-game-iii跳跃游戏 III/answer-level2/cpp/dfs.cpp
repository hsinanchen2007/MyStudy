### 解题思路
记忆化搜索

### 代码

```cpp
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visit(arr.size(), false);
        return canReach(arr, visit, start);
    }

    bool canReach(vector<int>& arr, vector<bool>& visit, int pos) {
        if (pos < 0 || pos >= arr.size()) return false;
        if (!arr[pos]) return true;
        if (visit[pos]) return false;
        visit[pos] = true;
        return canReach(arr, visit, pos + arr[pos]) || canReach(arr, visit, pos - arr[pos]);
    }
};
```