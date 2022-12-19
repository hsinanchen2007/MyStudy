类似题，最小加油次数
class Solution {
public:
    int jump(vector<int>& nums) {
        int now = 0;
        int i = 0;
        int step = 0;
        while (now < nums.size() - 1) {
            int far = 0;
            for (; i < nums.size() && i <= now; i++) {
                far = max(i + nums[i], far);
            }
            step++;
            now = far;
        }
        return step;
    }
};