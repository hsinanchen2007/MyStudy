## 不要总想着双指针法
**好好利用 “左侧所有元素相加的和等于右侧所有元素相加的和” 的条件**
```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        if(len==0) return -1;
        int sum=0, cur_sum=0;
        for(int i=0; i<len; i++) sum += nums[i];
        for(int i=0; i<len; i++){
            if(nums[i] == sum-2*cur_sum) return i;
            cur_sum += nums[i];
        }
        return -1;
    }
};
```