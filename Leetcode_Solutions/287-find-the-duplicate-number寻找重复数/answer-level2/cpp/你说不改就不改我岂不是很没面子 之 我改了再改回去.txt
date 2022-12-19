### 解题思路
对于i将nums[|nums[i]|]改成负数，如果已经是负数了，就是|nums[i]| 这个数
然后返回前再把之前改过负数的改回来。

### 代码

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            
            if (nums[abs(nums[i])] < 0)
            {
                for (int j = i; j >= 0; j--)//改回来
                {
                    int k = abs(nums[abs(nums[j])]);
                    nums[abs(nums[j])] = k;
                }
                return nums[i];
            }
            nums[abs(nums[i])] = -nums[abs(nums[i])];//改成相反数
        }
        return 0;
    }
};
```