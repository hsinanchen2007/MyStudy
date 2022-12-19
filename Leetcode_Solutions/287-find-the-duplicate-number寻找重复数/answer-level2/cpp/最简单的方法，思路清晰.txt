### 解题思路
排序，然后遍历
比如 1 3 4 2 2 排序后 1 2 2 3 4
然后遍历 找nums[i] == nums[i+1]就是那个重复的元素了

### 代码

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int N = nums.size() - 1;
        for(int i = 0; i < N;++i)
        {
            if(nums[i] == nums[i+1])
            {
                return nums[i];
            }
        }
        return 0;
    }
};
```