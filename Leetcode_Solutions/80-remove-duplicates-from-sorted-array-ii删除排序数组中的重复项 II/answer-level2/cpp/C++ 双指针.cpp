```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size(), i = 0;
        int repeat = 1, maxRepeat = 2;
        for (int j = 1; j < n; j++) {
            if (nums[j] == nums[i]) {
                if (repeat < maxRepeat) {
                    nums[++i] = nums[j];
                    repeat++;
                }
            } else {
                nums[++i] = nums[j];
                repeat = 1;
            }
        }
        return i + 1;
    }
};
```