### 解题思路
双指针遍历比较大小

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if(len==0||target<=nums[0])
            return 0;
        for(int i=0;i<len-1;i++)
        {
            if(target<=nums[i+1]&&target>nums[i])
                return i+1;
        }
        return len;
    }
};
```