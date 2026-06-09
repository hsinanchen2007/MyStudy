## 能改小就不改大
**这道题的重点在于：改变一个数的值，使当前遍历到的最大值尽可能小**
所以，有两种情况：
1. 如果当前数字只比前一个数字小，则使前一个数字等于它（而不使其等于前一个数字）
2. 如果当前数字比前两个数字都小，则使其等于前一个数字（只能这么改）
```cpp
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size(), cnt=0;
        if(len<3) return true;
        if(nums[1]<nums[0]){
            nums[0] = nums[1];
            cnt++;
        }
        for(int i=2; i<len; i++){
            if(nums[i]<nums[i-1]){ 
                cnt++;
                if(nums[i]>=nums[i-2]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
            }
            if(cnt>1) return false;
        }
        return true;
    }
};
```