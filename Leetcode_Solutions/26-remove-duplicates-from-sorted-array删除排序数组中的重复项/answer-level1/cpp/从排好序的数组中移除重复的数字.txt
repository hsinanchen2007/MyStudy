### 解题思路
12 ms, 在所有 C++ 提交中击败了95.51%的用户。
循环数组，然后比较该值是否在之前出现过，出现过就不管，没出现过就换到前面。
### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
          if(nums.size()<1){
        return 0;
    }
    int nonDuplicate = 0;
    int formerNum = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (formerNum == nums[i])
            continue;
        else
        {
            nonDuplicate++;
            nums[nonDuplicate] = nums[i];
            formerNum = nums[i];
        }
    }
    return nonDuplicate + 1;
    }
};
```