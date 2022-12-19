### 解题思路
利用 hashmap, key 为 vector 中的数, value 存放对应的下标。
遍历 vector, 若当前值已经存在于 hashmap 中，判断当前的下标与 hashmap 中记录的下标差是否不大于 k, 
若是，返回 true; 否则，更新 hashmap 中该值的下标，继续下一个数。

### 代码

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size(), idx = 0;
        unordered_map<int, int> nmap; // key:nums[i], value:index
        for (int i = 0; i < n; ++i) {
            auto iter = nmap.find(nums[i]);
            if (iter != nmap.end()) {
                if (i - iter->second <= k) return true;
                else iter->second = i;
            }
            else nmap[nums[i]] = i;
        }
        return false;
    }
};
```