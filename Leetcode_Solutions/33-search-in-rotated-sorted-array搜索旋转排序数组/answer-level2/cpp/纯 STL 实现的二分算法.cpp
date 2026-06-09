### 解题思路
尝试完全用 STL 里的 lower_bound 和 upper_bound 代替手写二分
    * lower_bound 对应的是 找一个最靠右的 check(x) == true
``` cpp
if (check(x)) l = m;
else r = m - 1;        
```
    * upper_bound 对应的是找一个最靠左的 check(x) == true
``` cpp
if (check(x)) r = m;
else l = m + 1;
```
### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        auto div = upper_bound(nums.begin(), nums.end(), nums.back(), [&](int a, int b) { return a >= b; });
        auto it = nums.begin();
        if (target <= nums.back()) it = lower_bound(div, nums.end(), target);
        else it = lower_bound(nums.begin(), div, target);
        if (it == nums.end() || *it != target) return -1;
        return it - nums.begin();
    }
};
```