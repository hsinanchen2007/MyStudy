参考官方提示的思路
```C++ []
class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        vector<int> nums;
        for (auto x : prices) {
            target -= stoi(x);
            int s = stoi(x.substr(x.size() - 3));
            if (s != 0) {
                nums.push_back(s);
            }
        }
        if (target > nums.size() || target < 0) return "-1";
        sort(nums.begin(), nums.end(), greater<int>());
        int delta = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (target > 0) {
                delta += 1000 - nums[i];
                --target;
            } else {
                delta += nums[i];
            }
        }
        char res[10];
        sprintf(res, "%.3f", 1.0 * delta / 1000);
        return string(res);
    }
};
```

![image.png](https://pic.leetcode-cn.com/d8d967759e9b97be98514e6f34aced2f0a374ccebc16430f499b48a7c833e399-image.png)
