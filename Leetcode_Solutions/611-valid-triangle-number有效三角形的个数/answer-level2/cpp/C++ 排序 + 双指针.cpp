```C++ []
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end(), greater<int>());
        int res = 0;
        int N = nums.size();
        for (int i = 0; i < N - 2; ++i) {
            int l = i + 1;
            int r = N - 1;
            while (l < r) {
                if (nums[l] + nums[r] <= nums[i]) {
                    --r;
                } else {
                    res += r - l;
                    ++l;
                }
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/3af173afcc687115f2407457435f1c6e544511ee992001cc117f6ef42df49d8e-image.png)
