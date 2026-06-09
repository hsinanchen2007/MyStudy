### 解题思路
逆序后交换
### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int lastpos = nums.size() - 1;
        while(lastpos > 0 && nums[lastpos] <= nums[lastpos-1]) --lastpos;
        reverse(nums.begin() + lastpos, nums.end()); // 逆序
        if(lastpos > 0){
            for(int i = lastpos; i < nums.size(); i++){
                if(nums[i] > nums[lastpos-1]){
                    swap(nums[i], nums[lastpos-1]); // 交换
                    break;
                }
            }
        }
        return;
    }
};
```