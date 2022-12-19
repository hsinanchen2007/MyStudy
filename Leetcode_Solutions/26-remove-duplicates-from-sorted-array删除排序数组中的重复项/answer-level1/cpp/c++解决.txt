### 解题思路

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int j=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]!=nums[i])
            {
                j++;
                nums[j]=nums[i+1];
            }
        }
        return j+1;
    }
};
```