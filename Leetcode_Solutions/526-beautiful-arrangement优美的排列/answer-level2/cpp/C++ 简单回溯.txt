```C++ []
class Solution {
public:
    void backtrace(vector<int>& nums, int i, int N, int& res) {
        if (i == N) ++res;
        for (int j = 0; j < N; ++j) {
            if (nums[j]) continue;
            if ((i + 1) % (j + 1) == 0 || (j + 1) % (i + 1) == 0) {
                nums[j] = i + 1;
                backtrace(nums, i + 1, N, res);
                nums[j] = 0;
            }
        }
    }
    int countArrangement(int N) {
        vector<int> nums(N, 0);
        int res = 0;
        backtrace(nums, 0, N, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/89e3a12ab984f301ec4b0051f37721b19ab94d16ed97ce43125fdbd532eebcea-image.png)
