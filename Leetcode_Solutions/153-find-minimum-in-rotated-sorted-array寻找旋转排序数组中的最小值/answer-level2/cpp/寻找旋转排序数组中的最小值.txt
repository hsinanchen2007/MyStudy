
二分法变种
-------------
```cpp
class Solution {
public:
    //因为是升序不重复，所以旋转之后，目标值以左为大数组，以右为小数组，大数组的值全部都大于小数组
    //mid在目标以左时：nums[mid]>nums[h];
    //mid在目标以右时：nums[mid]<=nums[h];
    //循环结束时，low所指即为所求
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid=0;
        //因为 high 的赋值表达式为 high = mid，因此循环条件为 low < high。
        while(low<high){
            mid=low+(high-low)/2;
            if(nums[mid]>nums[high]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return nums[low];
    }
};
```