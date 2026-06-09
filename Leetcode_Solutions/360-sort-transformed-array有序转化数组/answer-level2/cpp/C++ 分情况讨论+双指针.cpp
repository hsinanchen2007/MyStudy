```
class Solution {
public:
    int f(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (a == 0) {
            vector<int> res;
            for (auto x : nums) res.push_back(f(x, a, b, c));
            if (b < 0) reverse(res.begin(), res.end());
            return res;
        }
        double m = -(double)b / (2 * a);
        int N = nums.size();
        int i = 0;
        while (i < N && nums[i] < m) ++i;
        int l = max(i - 1, 0);
        int r = max(min(i, N - 1), l + 1);
        vector<int> res;
        while (l >= 0 && r < N) {
            if (m - nums[l] < nums[r] - m) res.push_back(f(nums[l--], a, b, c));
            else res.push_back(f(nums[r++], a, b, c));
        }
        while (l >= 0) res.push_back(f(nums[l--], a, b, c));
        while (r < N) res.push_back(f(nums[r++], a, b, c));
        if (a < 0) reverse(res.begin(), res.end());
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/ad7e1e05dfe8a1ee16c38fd67de4daa18fdab7c5e8a399b291d2a86441f72700-image.png)
