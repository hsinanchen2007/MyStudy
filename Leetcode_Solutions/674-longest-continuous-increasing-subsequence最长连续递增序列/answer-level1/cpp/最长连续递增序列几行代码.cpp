```
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
                int sum = 1;
                int temp = 1; 
                for (int i = 0; i < nums.size() - 1; ++i) {
                    temp = nums[i] < nums[i+1] ? ++temp : 1;
                    sum = sum > temp ? sum : temp;
                }
                return sum;
    }
};
```
