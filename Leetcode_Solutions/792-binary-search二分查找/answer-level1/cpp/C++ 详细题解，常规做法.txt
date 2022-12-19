### 思路
- 设定数组的开头和尾端为左右边界，mid为(l + r)/2
- 若target大于mid 将l赋值为mid，重新计算mid值
- 若target小于mid 将r赋值为mid，重新计算mid值
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int l = 0;
        int r = nums.size() - 1;
        int mid = (l + r) / 2;
        if(nums[0] == target)   return 0; //数组仅有一位的情况或刚好第零个为目标值的情况
        if(nums[mid] == target) return mid; //初始mid为目标值的情况
        while(nums[mid] != target){
            if(mid == l){ //当左右边界相邻时，mid的结果总是等于左边界
                if(nums[mid] == target) return mid;
                else if(nums[r] == target)  return r;
                else return -1;
            }
            if(nums[mid] > target){
                r = mid;
            }
            else{
                l = mid;
            }
            mid = (l + r) / 2;
            ans = mid;
        }
        return ans; 
    }
};
```
