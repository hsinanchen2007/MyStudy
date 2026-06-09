### 解题思路
此处撰写解题思路
参考剑指offer思路
### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if(nums.empty()){
            return -1;
        }
        for(int i = 0; i<nums.size();i++){
            while(nums[i] != i){
                if(nums[i] == nums[nums[i]]){
                    return nums[i];
                }
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return -1;
    }
};
```