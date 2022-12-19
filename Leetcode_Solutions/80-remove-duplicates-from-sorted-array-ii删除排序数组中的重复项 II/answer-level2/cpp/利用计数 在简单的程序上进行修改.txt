### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.size() <= 0) return 0;
        int j = 0;
        int count = 0;
        for(int i = 1;i < nums.size();i++)
        {
            if(nums[i] != nums[j])
            {
                j++;
                nums[j] = nums[i];
                count = 0;
            }else if(nums[i] == nums[j]  && count <= 0)
            {
                j++;
                nums[j] = nums[i];
                count++;
            }
        }
        return j + 1;
    }
};
```