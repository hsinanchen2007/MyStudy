![1 (2).png](https://pic.leetcode-cn.com/0e2418138cfe3138e46214298ee74cc717744cbca3893ad2c4be3e5c49012c7f-1%20\(2\).png)

### 代码

```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnt;
        unordered_set<int> cache;

        for (auto a : arr) cnt[a]++;
        for (auto c : cnt) {
            if (cache.count(c.second)) return false;
            else cache.insert(c.second);
        }

        return true;
    }
};
```