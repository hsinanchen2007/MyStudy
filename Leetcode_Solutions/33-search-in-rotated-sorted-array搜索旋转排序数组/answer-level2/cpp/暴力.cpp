### 解题思路
此处撰写解题思路
二分查找  嗯，判断的地方多，直接暴力解决
### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())return -1;
        if(target == nums[0])return  0;
        else if(target > nums[0]){
            int min = nums[0];
            for(int i = 1;i < nums.size();i++){
                if(target == nums[i])return i;
                if(nums[i] < min || target < nums[i])break;
            }
        }
        else{
            int max = nums[0];
            for(int i = nums.size()-1;i > 0;i--){
                if(target == nums[i])return i;
                if(nums[i] > max || target > nums[i])break;
            }
        }
        return -1;
    }
};
```