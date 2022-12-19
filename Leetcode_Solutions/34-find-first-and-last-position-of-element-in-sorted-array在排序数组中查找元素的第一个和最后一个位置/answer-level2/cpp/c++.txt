### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> ret(2,-1);
        for (int l = 0, r = size -1; l<=r;){
            int mid = l + (r - l)/2;
            int n = nums[mid];
            if (n < target)
                l = mid + 1;
            else
            if ( n >= target){
                r = mid - 1;
                if(n == target)
                    ret[0] = mid;
            }
        }

        for (int l = 0, r = size -1; l<=r;){
            int mid = l + (r - l)/2;
            int n = nums[mid];
            if (n > target)
                r = mid - 1;
            else
            if ( n <= target){
                l = mid + 1;
                if(n == target)
                    ret[1] = mid;
            }
        }    
        return ret;   
    }
};
```