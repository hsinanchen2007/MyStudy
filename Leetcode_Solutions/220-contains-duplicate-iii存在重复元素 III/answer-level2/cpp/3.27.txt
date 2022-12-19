### 解题思路
并不是查找一个元素，而是查找一个范围内的元素是否存在，所以需要使用set而不是unordered_set，这里还需要了解的是lower_bound(val)返回set中大于或等于val的第一个元素位置。如果所有元素都小于val，则返回last的位置。
如果lower_bound(nums[i] - t)返回值小于等于nums[i] + t，则直接返回true，否则继续遍历nums[i]。


### 代码

```cpp
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s;
        for(int i = 0; i < nums.size(); i++)
        {
            auto it = s.lower_bound(nums[i] - long(t));
            if(it != s.end() && *it - nums[i] <= t) 
            {
                return true;
            }
            s.insert(nums[i]);
            if(s.size() > k) 
            {
                s.erase(nums[i - k]);
            }
        }
        
        return false;
    }
};
```