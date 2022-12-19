### 解题思路
![image.png](https://pic.leetcode-cn.com/df1ab5a90cb5e2fe42d474fb8b4fc23b79a2da1840785a38489a56e13cdcc6e2-image.png)

这里的动态规划数组m，是指打劫第i家时的最大金额
所以最后的答案是max(m[len - 1], m[len - 2])

转移方程
m[i] = max(m[i-2], m[i-3]) + nums[i];
### 代码

```cpp
class Solution {
public:
    //dp
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = nums.size();
        if (len < 2) return nums[0];
        vector<int> m(len, 0);
        m[0] = nums[0];
        m[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len; i++) {
            if (i == 2) {
                m[i] = m[0] + nums[i];
                continue;
            } 
            m[i] = max(m[i-2], m[i-3]) + nums[i];
        }
        return max(m[len - 1], m[len - 2]);
    }
};
```