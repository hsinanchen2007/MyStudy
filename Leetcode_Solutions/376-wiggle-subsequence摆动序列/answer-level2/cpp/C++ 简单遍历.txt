```C++ []
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int N = nums.size();
        if (N < 2) return N;
        int prev = 0;
        int res = 1;
        for (int i = 1; i < N; ++i) {
            if (nums[i] == nums[i - 1]) continue;
            int curr = (nums[i] > nums[i - 1]) ? 1 : -1;
            res += curr != prev;
            prev = curr;
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/ed679f9312c650ef8b364e202a28dcd342f621caeecc233d2648a90e2014b5c4-image.png)
