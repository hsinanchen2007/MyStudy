### 解题思路
1，将Y迭代分解成半截（至少一半）
2，然后看将X去靠拢Y的半截数组，看怎么靠拢最快到达Y

### 代码

```cpp
class Solution {
public:
    vector<int> nums;
    int brokenCalc(int X, int Y) {
        if (X >= Y) return X - Y;
        nums.push_back(Y);
        int t = Y;
        while (t > 1) {
            nums.push_back((t + 1) >> 1);
            t = (t + 1) >> 1;
        }
        int N = nums.size();
        reverse(nums.begin(), nums.end());
        int k = lower_bound(nums.begin(), nums.end(), X + 1) - nums.begin();
        vector<int> steps(N, 0);
        for (int i = N - 2; i >= 0; --i) {
            steps[i] += steps[i + 1] + 1 + (nums[i] << 1) - nums[i + 1];
        }
        int res = INT_MAX;
        int s = X;
        for (int i = k - 1; i < N; ++i) {
            res = min(res, i - k + 1 + s - nums[i] + steps[i]);
            s <<= 1;
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/d6f8c9029199d9e3c5f38ddda5ef42a806738baf620f82ccd522082610e50704-image.png)
