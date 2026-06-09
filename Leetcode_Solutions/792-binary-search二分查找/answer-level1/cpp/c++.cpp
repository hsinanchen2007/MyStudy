

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty() || nums[nums.size()-1] < target) return -1; 
        int l = 0;
        int r = nums.size()-1;
        while(l < r){
            int mid = l+r+1 >> 1;
            if(nums[mid] <= target)l = mid;
            else r = mid - 1;
        }
        return nums[l] == target ? l : -1;
    }
};
```