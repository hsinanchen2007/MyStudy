### 解题思路


### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)return 0;
        int i = 0;
        int len = 1;
        for (int j = 1 ; j < nums.size() ; j++){
            if(nums[j] != nums[i]){
                i++;
                swap(nums[i] , nums[j]);
                len++;
            }
        }
        return len;
    }
};
```