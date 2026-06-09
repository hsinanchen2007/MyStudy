### 解题思路
**暴力法：**
**从第一个数开始遍历数组，找出一个最大的子序列和，再从第二个数开始，找出最大的子序和，以此类推**

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //理论上存在有子序和为最小值的情况，所以初始值设置成最小值：
        int max = INT_MIN;
        int size = nums.size();
        for(int i = 0 ; i < size ; i++)
        {
            int sum = 0 ; 
            for(int j = i ; j < size ; j++)
            {
                sum += nums[j];
                if(sum > max)
                {
                    max = sum;
                }
            }
        }

        return max;
    }
};
```