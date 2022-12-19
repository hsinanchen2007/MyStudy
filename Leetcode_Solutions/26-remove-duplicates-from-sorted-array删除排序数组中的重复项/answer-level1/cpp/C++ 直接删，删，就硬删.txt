### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool if_need_del = false;
        for (int i = 0; i < nums.size();) {
            int index_val = nums[i];
            if (i+1 < nums.size() && index_val == nums[i+1]){
                vector<int>::iterator pos = find(nums.begin(), nums.end(), index_val);
                if (pos != nums.end()) 
                    nums.erase(pos);
            } else {
                ++i;
            }
        }
        return nums.size();
    }
};
```