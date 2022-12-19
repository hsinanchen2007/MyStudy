```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, i = 0;

        while (l <= r){
            if (nums[l] == 0){
                swap(nums[i++], nums[l++]);
            }
            else if (nums[l] == 2){
                swap(nums[r--], nums[l]);
            }
            else {
                l++;
            }
        }
    }
};
```