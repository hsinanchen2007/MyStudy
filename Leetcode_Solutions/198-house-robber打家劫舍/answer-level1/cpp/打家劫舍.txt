### 解题思路
经判断有最优解结构。
可以用递归或者动态规划求解。
首先判断退出条件，也就是当数组长度为1或为2时，可以直接计算最优值m[0],[1]。
当长度大于2时，第i(i>1)个元素的取与不取分成两种情况：
最优值m[i]=max(m[i-2]+nums[i],m[i])。

此种题可以先写递归解法，有时候会通过，有时候会因为空间或者时间限制通过不了。

### 代码

```cpp
class Solution {
public:
    int rob(vector<int> &nums) {
        if(nums.size()<1)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        vector<int> m;
        m.push_back(nums[0]);
        m.push_back(max(nums[0],nums[1]));
        
        for(int i=2;i<nums.size();i++)
           m.push_back(max(m[i-2]+nums[i],m[i-1]));
        
        return m.back();
    }
};
```