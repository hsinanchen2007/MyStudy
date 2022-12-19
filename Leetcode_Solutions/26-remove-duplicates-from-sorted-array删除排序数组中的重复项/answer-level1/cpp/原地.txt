### 解题思路
此处撰写解题思路

### 代码

```cpp
//2020年3月26日
//原地操作
//排序好的，说明不会有间隔重复的情况

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int new_index = 1;
        for(int i = 1 ; i < nums.size() ; i++)
        {
            if(nums[i] == nums[i-1])
            continue;
            nums[new_index++] =nums[i];
        }
        return new_index;
    }
};
```