# 思路：
与下一个更大元素III一模一样
[见题解](https://leetcode-cn.com/problems/next-greater-element-iii/solution/c-xun-zhao-zui-hou-yi-ge-shun-xu-dui-by-da-li-wang/)
```C++ []
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int N = nums.size();
        int l = -1;
        for (int i = 1; i < N; ++i) {
            if (nums[i] > nums[i - 1]) {
                l = i - 1;
            }
        }
        if (l == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        reverse(nums.begin() + l + 1, nums.end());
        int r = upper_bound(nums.begin() + l + 1, nums.end(), nums[l]) - nums.begin();
        swap(nums[l], nums[r]);
    }
};
```

![image.png](https://pic.leetcode-cn.com/93fcb6cb4f1f2c398d8b70fb810347a1192031405b358f7980bf3abda663e8b8-image.png)
