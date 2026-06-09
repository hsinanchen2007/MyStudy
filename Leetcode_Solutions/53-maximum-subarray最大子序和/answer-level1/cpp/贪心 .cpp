![image.png](https://pic.leetcode-cn.com/e89ce796a68fbcd3c8c9c094865e1f3f247612386f5b09bcf1a34a73b04412fb-image.png)

### 解题思路
循环整个数组，判断每个元素是否可能被添加到一个可能成为最大子序列和的子序列之中。         
判断条件为，当前元素与上一个元素之和要大于当前元素（说明上一个元素不为负数，则上一个元素可能是子序列元素），若满足则将当前元素修改为两元素之和。         
我们另`max=nums[0]`，然后直接从第二个元素遍历。

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tmp, max = nums[0];
        for (int i=1; i<nums.size(); i++)
        {
            tmp = nums[i] + nums[i-1];
            if (tmp > nums[i])
            {
                nums[i] = tmp; 
                max = tmp>max?tmp:max;
            }
            else
            {
                max = nums[i]>max?nums[i]:max;
            }
        }
        return max;
    }
};
```