```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min = INT_MAX;
        int sum = 0;
        //如何遍历3数之和？巧解？暴力(估计时间会溢出)
        //思路：先排序数组,然后选定数组中一个数字,剩下的两个数字从两边往中间靠进行选择
        //如果结果更小,则low右移,如果结果更大,hi左移
        //如何判断两个数是否接近? |a - b|更小
        std::sort(nums.begin(),nums.end());
        const int SIZE = nums.size();//如果将SIZE声明为static将会报错,说明leetcode的测试代码中有用到SIZE变量=。=
        for (int i = 0;i < SIZE - 2;++i) {
            auto now = i;
            auto low = i + 1;
            auto hi = SIZE - 1;
            while (low < hi) {
                auto tmp_sum = nums[now] + nums[low] + nums[hi];
                if (tmp_sum == target) return target;//如果恰好找到目标值,直接返回
                auto tmp = abs(tmp_sum - target);
                if (tmp < min) {//更新sum的逻辑是看差值是否更小
                    min = tmp;
                    sum = tmp_sum;
                }
                if (tmp_sum < target) {//移动那边的逻辑是看总和比target大还是小
                    ++low;
                } else {
                    --hi;
                }
            }
        }
        return sum;
    }
};
```
