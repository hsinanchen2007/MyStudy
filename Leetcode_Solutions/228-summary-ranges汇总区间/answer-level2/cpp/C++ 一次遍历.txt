```C++ []
class Solution {
public:
    string convert(int left, int right) {
        string res;
        if (left == right) {
            res = to_string(right);
        } else {
            res = to_string(left) + "->" + to_string(right);
        }
        return res;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        int left = nums[0];
        int right = nums[0];
        int N = nums.size();
        vector<string> res;
        for (int i = 1; i < N; ++i) {
            if ((long)nums[i] - (long)nums[i - 1] > 1) {
                res.push_back(convert(left, right));
                left = right = nums[i];
            } else {
                right = nums[i];
            }
        }
        res.push_back(convert(left, right));
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/4fecffad14e7128de1204a735773a8a7162b22c5f167656ecc40febca9a84f1b-image.png)
