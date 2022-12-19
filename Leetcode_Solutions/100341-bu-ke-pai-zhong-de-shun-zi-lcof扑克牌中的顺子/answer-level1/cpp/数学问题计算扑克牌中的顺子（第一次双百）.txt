### 解题思路
首先对数组排序，然后统计零的个数。如果有两个值相等的话，立即返回False；计算往两个非零数值间插入“零”的个数count，如果count>零的个数，返回False，否则返回True。
![捕获.JPG](https://pic.leetcode-cn.com/ec6d115c10dc72cbfc6be863fd613d099f3792ce9daab705575ecbb8ea54a96f-%E6%8D%95%E8%8E%B7.JPG)


### 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int zero = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == 0) {
                zero++;
                continue;
            }
            if (nums[i] == nums[i + 1]) {
                return false;
            }
            zero = zero - (nums[i + 1] - nums[i] - 1);
        }
        return zero >= 0;
    }
};
```