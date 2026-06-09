### 解题思路
map 记录出现次数，返回最大值即可。

### 代码

```cpp
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int l = arr.size();
        unordered_map<int, int> mp;
        for(auto a : arr) {
            mp[a]++;
        }
        int maxlucky = -1;
        for(auto m : mp) {
            if(m.first == m.second) {
                maxlucky = max(maxlucky, m.first);
            }
        }
        return maxlucky;
    }
};
```