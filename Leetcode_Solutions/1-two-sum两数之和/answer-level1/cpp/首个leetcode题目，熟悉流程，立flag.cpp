### 解题思路
首个leetcode题目，熟悉一下leetcode刷题流程！
立个flag！！！
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for(i=0;i<nums.size()-1;i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(target==nums[i]+nums[j])
                return {i,j};
            }
        }
        return{i,j};
    };
};
```