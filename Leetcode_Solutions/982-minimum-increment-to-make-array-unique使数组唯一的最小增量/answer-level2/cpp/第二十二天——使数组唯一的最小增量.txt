### 解题思路
效率极其低下的算法

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int res = 0;
        unordered_map<int, int> mp;
        for(int i:A) mp[i]++;
        for(int i = 0; i <= 40000+A.size(); i++){
            if(mp[i] > 1) res += mp[i] - 1, mp[i+1] += mp[i] - 1;
        }
        return res;
    }
};
```