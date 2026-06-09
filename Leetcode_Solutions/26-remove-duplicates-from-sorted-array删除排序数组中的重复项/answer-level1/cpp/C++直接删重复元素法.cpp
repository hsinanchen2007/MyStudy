### 解题思路
遇到重复元素就删删删😀

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        
        int i=1;
        int maxn = nums[nums.size()-1];
        while (i < nums.size() && nums[i] <= maxn) { // 边界
            if (nums[i] == nums[i-1])  // 删到不敢重复，删掉元素，元素前移，因此不须 i++
                nums.erase(nums.begin() + i);
            else
                i++;
        }
        return i;
    }
};
```