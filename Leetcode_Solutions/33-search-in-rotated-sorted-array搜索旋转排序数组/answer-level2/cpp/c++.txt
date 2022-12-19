### 解题思路
100% 

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())return -1; 
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = l+r >> 1;
            if(nums[mid] <= nums.back())r = mid;
            else l = mid+1;
        }
        if(target <= nums.back())r = nums.size()-1;
        else{
            r = r-1;
            l = 0;
        }
        while(l < r){
            int mid = l+r+1 >> 1;
            if(nums[mid] <= target)l = mid;
            else r = mid - 1;
        }
        return nums[l] == target ? l : -1;
    }
};
```