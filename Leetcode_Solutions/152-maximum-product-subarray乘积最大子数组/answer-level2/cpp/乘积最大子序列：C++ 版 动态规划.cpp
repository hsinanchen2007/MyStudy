### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = (1<<31), curMax = 1, curMin = 1; // 需要维护当前最大和最小值
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){       // 当前值为负数时，交换最大最小值
                int tmp = curMax;
                curMax = curMin;
                curMin = tmp;
            }
            // 动态规划
            curMax = max(curMax * nums[i], nums[i]); // 取较大值
            curMin = min(curMin * nums[i], nums[i]); // 取较小值
            
            result = max(curMax, result);
        }
        return result;
    }
};
```