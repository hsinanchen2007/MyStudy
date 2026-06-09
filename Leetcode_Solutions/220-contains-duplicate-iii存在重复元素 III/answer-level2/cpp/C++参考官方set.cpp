### 解题思路
The lower_bound() function returns an iterator to the first element which has a value **greater** than or **equal** to key.

The upper_bound() function returns an iterator to the first element in the set with a key **greater** than key.

### 代码

```cpp
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s; //必须set 从小到大排序

        for (int i = 0; i < nums.size(); i++) {
            //先找下界 （nums[i] - t）
            auto it = s.lower_bound((long)nums[i] - (long)t); //注意需要用lower_lound（>=）
            //若下界找到了，并且小于上界（nums[i] + t），则OK
            if (it != s.end() && *it <= ((long)nums[i] + (long)t)) {
                return true;
            }
            
            s.insert(nums[i]);
            if (s.size() > k) {
                s.erase(nums[i-k]);
            }
        }
        return false;
    }
};
```