### 解题思路
动态规划的思路，自下而上，以每个元素为结尾，计算这个元素之前所有元素的最大和。
递推公式d[i] = max(d[i-1] + nums[i], nums[i])

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        vector<int> d;
        int l = nums.size();
        d.resize(l);
        d[0] = nums[0];
        int max_num = d[0];
        for (int i = 1; i < l; i++) {
            d[i] = max(d[i-1] + nums[i], nums[i]);
            if (d[i] > max_num) {
                max_num = d[i];
            }
        }
        return max_num;        
    }
};
```