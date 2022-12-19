### 解题思路
暴力解法，第一次出错是因为忘记添加return{}这种情况，属实不该。

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
   int t=nums.size();
    int i;
    int j;
    for(i=0;i<t;i++){
        for(j=1;j<t;j++)
            if(nums[i]+nums[j]==target&&i!=j)
                return {i, j};
    }
    return {};
    }
};
```