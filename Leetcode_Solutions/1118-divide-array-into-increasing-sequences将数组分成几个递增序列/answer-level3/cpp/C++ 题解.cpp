```
class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        int s = 0;
        int left = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[left]) {
                s = max(s, i - left);
                left = i;
            }
        }
        s = max(s, (int)nums.size() - left);
        return s * K <= nums.size();
    }
};
```

![image.png](https://pic.leetcode-cn.com/dbbbe85b492a7cb7a8907d0b6f69a0aade839a8ed396b5d9490ac8da982e11d5-image.png)
