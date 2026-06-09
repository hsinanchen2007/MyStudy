# 思路：
1，将数字拆成位数组`nums`
2，寻找数组的最后一个顺序对`[i, i + 1]`，记录左侧的下标`i`
3，将`i`右侧数组进行翻转，右侧就变成了升序序列
（因为`i`右侧不再有顺序对，也就是说都是逆序对了，因此翻转了就是升序序列）
4，`i`右侧二分查找到比`nums[i]`大的最小值`nums[j]`，交换`nums[i]`，`nums[j]`就是结果
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
    int nextGreaterElement(int n) {
        vector<int> nums = digits(n);
        int N = nums.size();
        int l = -1;
        for (int i = 1; i < N; ++i) {
            if (nums[i] > nums[i - 1]) {
                l = i - 1;
            }
        }
        if (l == -1) return -1;
        reverse(nums.begin() + l + 1, nums.end());
        int r = upper_bound(nums.begin() + l + 1, nums.end(), nums[l]) - nums.begin();
        swap(nums[l], nums[r]);
        long res = 0;
        for (int i = 0; i < N; ++i) {
            res = 10 * res + (long)nums[i];
        }
        return res > INT_MAX ? -1 : res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/313ef11157149c42f31217e9fddf4f9d60c6aabd163f05f96119129f990d0c19-image.png)
