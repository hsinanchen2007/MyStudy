class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        long long ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int sb = 0;
            int temp = 0;
            for(int j = 2; j * j <= nums[i]; ++j) {
                if(nums[i] % j == 0) {
                    sb++;
                    temp = j;
                }
                if(nums[i] == j * j) {
                    sb = 0;
                }
                if(sb > 1) {
                    break;
                }
            }
            if(sb == 1) {
                ans += nums[i] + temp + nums[i] / temp + 1;
            }
        }
        return ans;
    }
};