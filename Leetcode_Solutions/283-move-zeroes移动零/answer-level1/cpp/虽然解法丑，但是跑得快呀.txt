```
思路：
- 双指针（慢指针、快指针）从第一个第二个开始
- 快指针遇到非零且慢指针为0，交换，在双双+1
- 慢指针非零且快指针为0，双双+1
- 都为0，只有快指针+1
- 都不为0，双双+2，跑得快

class Solution {
public:    
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 1;
        while (j < nums.size()) {
            if (nums[i] == 0 && nums[j] != 0) {
                nums[i] = nums[j];
                nums[j] = 0;
                i++;
                j++;
            } else if (nums[i] != 0 && nums[j] == 0) {
                i++;
                j++;
            } else if (nums[i] == 0 && nums[j] == 0) {
                j++;
            } else {
                i += 2;
                j += 2;
            }
        }
    }
};
```
