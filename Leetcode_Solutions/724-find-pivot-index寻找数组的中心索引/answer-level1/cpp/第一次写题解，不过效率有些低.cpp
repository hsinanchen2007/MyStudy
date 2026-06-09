class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        int s = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(sum - nums[i] - s == s)
            return i;
            s += nums[i];
        }
        return -1;
    }
};
// static const auto io_speed_up=[]{
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     return 0;
// }();