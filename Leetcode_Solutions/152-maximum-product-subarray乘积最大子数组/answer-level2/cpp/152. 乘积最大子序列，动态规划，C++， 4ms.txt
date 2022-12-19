### 解题思路

![image.png](https://pic.leetcode-cn.com/7e21501a5ea2ee465968be594474d55c466bc27dfdb9db407a613094ede0cbfa-image.png)
考虑，乘积最大，那么有可能是之前的最小值跳到最大，也有可能是最大值跳到最大

所以需要维护两个队列，最小值队列与最大值队列，每次计算
nums[i] * m_max[i-1]
nums[i] * m_min[i-1]
其中，m_max[i] = max(nums[i], nums[i] * m_max[i-1], nums[i] * m_min[i-1])
其中，m_min[i] = min(nums[i], nums[i] * m_max[i-1], nums[i] * m_min[i-1])
### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = nums.size();
        vector<int> m_max(len, 0);
        vector<int> m_min(len, 0);
        m_max[0] = nums[0];        
        m_min[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < len; i++) {
            int m = nums[i];
            int l = m * m_max[i-1];
            int r = m * m_min[i-1];
            m_max[i] = max(l, m);
            m_max[i] = max(m_max[i], r);  
            res = max(res, m_max[i]);
            m_min[i] = min(r, m);
            m_min[i] = min(m_min[i], l);
        }   
        return res;     
    }
};
```