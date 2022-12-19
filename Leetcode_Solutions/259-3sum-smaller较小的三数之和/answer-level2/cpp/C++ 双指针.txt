```c++ []
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        long tgt = target;
        int res = 0;
        for (int i = 0; i < N; ++i) {
            long v = nums[i];
            int l = i + 1;
            int r = N - 1;
            while (l < r) {
                long vl = nums[l];
                long vr = nums[r];
                if (v + vl + vr < target) {
                    res += r - l;
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/5d64fcce5d081d643e50be22de333365b126265edf51a0965c56672e52583559-image.png)
