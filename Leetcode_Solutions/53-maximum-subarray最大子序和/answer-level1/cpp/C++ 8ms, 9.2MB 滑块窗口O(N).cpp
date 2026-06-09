### 解题思路
滑块窗口模板题
维护一段连续序列，一旦序列和小于0（也就是说这一段序列对区间和的贡献为负），就清空序列，重新开始计数。
其他例题可以参考bzoj等

![image.png](https://pic.leetcode-cn.com/e2fc967822ab3595bea6f2ee4cf8f1ebce8146ef6e659a4b4648d03a6691f9bd-image.png)

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 特殊情况处理
        if(nums.size() == 0) return nums[0];
        // ans 记录答案，sum 记录序列和
        int ans = nums[0], sum = nums[0];
        for(int i = 1; i < nums.size(); i ++)
        {
            if(sum < 0) sum = 0;
            sum += nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};
```