### 解题思路
利用二分的思想，把区间分成两段，查找满足条件的边界下标！一直找满足条件的边界。

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        
        if(nums[l] != target){
            return {-1,-1};
        }
        else{
            int n = l;
            l = 0, r = nums.size() - 1;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(nums[mid] <= target) l = mid;
                else r = mid - 1;
            }
            return {n, l};
        }
        return {-1, -1};
    }
};
```