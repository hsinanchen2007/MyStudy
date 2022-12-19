### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()<=1)
        return nums.size();
        int result(1);
        int i=0;
        int j;
        for(j=1;j<nums.size();j++)
        {
            if(nums[j]<=nums[j-1])
            {
                result=result>j-i?result:j-i;
                i=j;
            }
        }
        result=result>j-i?result:j-i;
        return result;
    }
};
```