# 思路：
1，先将数每一位拆成数组
2，若数组为非升序序列，则直接返回原数即可
3，否则，就找到数组中第一次出现升序的位置，从该位置往后找到最后一个最大值`max_val`及其下标`max_ind`
4，从数组头开始找第一个比`max_val`小的数的下标`i`，交换`i`与`max_ind`位置的数即可
```C++ []
class Solution {
public:
    vector<int> digits(int n) {
        vector<int> res;
        while (n > 0) {
            res.push_back(n % 10);
            n /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int maximumSwap(int num) {
        vector<int> nums = digits(num);
        int i = 1;
        int N = nums.size();
        while (i < N && nums[i] <= nums[i - 1]) ++i;
        if (i == N) return num;
        
        int max_val = nums[i];
        int max_ind = i;
        for (; i < N; ++i) {
            if (nums[i] >= max_val) {
                max_val = nums[i];
                max_ind = i;
            }
        }
        for (i = 0; i < N; ++i) {
            if (nums[i] < max_val) {
                break;
            }
        }
        swap(nums[i], nums[max_ind]);
        int res = 0;
        for (auto x : nums) {
            res = 10 * res + x;
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/a3d7502c2d5ff321d1024dca836d5b51c7ea768fd64464986ec3e57984e8b245-image.png)
