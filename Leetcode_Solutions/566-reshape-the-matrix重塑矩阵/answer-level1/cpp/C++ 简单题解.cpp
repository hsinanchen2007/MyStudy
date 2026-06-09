### 解题思路
简单遍历即可
不过需要注意r * c溢出的问题

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty() || nums[0].empty()) return nums;
        int R = nums.size();
        int C = nums[0].size();
        int N = R * C;
        if (N % r != 0 || N / r != c) return nums;
        vector<vector<int> > res(r, vector<int>(c, 0));
        for (int i = 0; i < N; ++i) {
            res[i / c][i % c] = nums[i / C][i % C];
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/50aefbdad8a4578c44df800f293be15985933973a3ed0db1ca89ac95a59c48b0-image.png)
