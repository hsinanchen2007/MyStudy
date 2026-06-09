```c++
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() / 2;
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += nums[i * 2];
        }
        return s;
    }
};
```