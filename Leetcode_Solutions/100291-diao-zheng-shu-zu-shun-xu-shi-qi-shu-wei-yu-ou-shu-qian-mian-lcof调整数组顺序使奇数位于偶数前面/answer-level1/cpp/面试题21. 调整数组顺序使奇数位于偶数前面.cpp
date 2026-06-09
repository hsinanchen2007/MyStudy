指针对撞
```cpp 
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {

        if (nums.size() == 0|| nums.size() == 1)
            return nums;
        
        int l = 0, r = nums.size()-1;
        while (l < r) {
            while (l < r && nums[l] % 2 )
                l++;
            while(l < r && !(nums[r] % 2))
                r--;
            if (l < r)
                swap(nums[l], nums[r]);
        }

        return nums;
        
    }
};
```