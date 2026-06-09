### 解题思路
参考官方题解，C++战胜双百

### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i;
        for (i = size - 1; i > 0; i--) {
            if (nums[i] > nums[i-1]) {
                break;
            }
        }
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j;
        for (j = i; j < size; j++) {
            if (nums[j] <= nums[i-1]) {
                break;
            }            
        }
        int tmp = nums[i-1];
        nums[i-1] = nums[j-1];
        nums[j-1] = tmp;
        reverse(nums.begin() + i, nums.end());
        return;
    }
};
```