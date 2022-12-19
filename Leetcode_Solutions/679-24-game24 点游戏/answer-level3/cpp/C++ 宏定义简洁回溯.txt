```
# define ADD +
# define SUB -
# define MUL *
# define DIV /
# define JUDGE(nums, target, a, b, op) \
    do { \
        nums.push_back(a op b); \
        if (judge(nums, target)) return true; \
        nums.pop_back(); \
    } while (0)

class Solution {
public:
    bool judge(const vector<double>& nums, double target) {
        int s = nums.size();
        if (s == 1)
            return (nums[0] < target + 1e-8) && (nums[0] > target - 1e-8);
        for (int i = 0; i < s; ++i) {
            for (int j = i + 1; j < s; ++j) {
                vector<double> new_nums;
                for (int k = 0; k < s; ++k) {
                    if (k != i && k != j)
                        new_nums.push_back(nums[k]);
                }
                double a = nums[i];
                double b = nums[j];
                JUDGE(new_nums, target, a, b, ADD);
                JUDGE(new_nums, target, a, b, MUL);
                JUDGE(new_nums, target, a, b, SUB);
                JUDGE(new_nums, target, b, a, SUB);
                if (b != 0) JUDGE(new_nums, target, a, b, DIV);
                if (a != 0) JUDGE(new_nums, target, b, a, DIV);
            }
        }
        return false;
    }
    bool judgePoint24(const vector<int>& nums) {
        vector<double> new_nums(nums.begin(), nums.end());
        return judge(new_nums, 24);
    }
};

```
