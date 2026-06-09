### 解题思路
先排序，然后比较相邻数据是否有相同的。
这里需要注意首位的特殊性，需要单独判断。

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[0] != nums[1]) return nums[0];
        if(nums[nums.size()-2] != nums[nums.size() -1]) return nums[nums.size() -1];
        for(int i=1;i<nums.size() - 1;i++)
        {
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1]) return nums[i];
        }
        return 0;
    }
};
```