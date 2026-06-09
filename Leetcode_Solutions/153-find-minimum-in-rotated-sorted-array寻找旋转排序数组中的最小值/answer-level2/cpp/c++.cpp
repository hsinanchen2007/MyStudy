###思路
二分寻找最后一个满足条件的元素

### 代码

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())return -1;       
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = l+r >> 1;
            if(nums[mid] <= nums.back())r = mid;
            else l = mid+1;
        }
        return nums[r];
    }
};
```