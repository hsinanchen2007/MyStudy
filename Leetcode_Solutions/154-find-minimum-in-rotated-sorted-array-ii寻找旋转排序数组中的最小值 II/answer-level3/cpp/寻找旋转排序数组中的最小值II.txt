/*
由于在while里面的判断是以nums[0]进行比较的，
条件(1):当nums[mid-1]<nums[mid]<=nums[mid]时，条件成立，返回。允许nums[mid]<=nums[mid+1]是因为最小值可能是重复的
条件(2):当nums[mid]在最小值右侧时，right变小
条件(3):当nums[mid]在最小值左侧时，left变大，同样的，允许nums[mid]>=nums[0]是因为nums[mid]可能是重复的。

(4)接下来就是一些特殊条件的判断，比如只有一个数vector与没有旋转的情况下都是返回第一个元素
(5)应该是最特殊的，最小值的左右两侧都是同样大小的元素并且nums[mid]落入这些元素区间中，将会不知道往那边判断，所以先消除
*/
class Solution {
public:
    int findMin(vector<int>& nums) {

        //(4)
        if(nums.size() == 1||nums[0] < nums[nums.size()-1]) return nums[0]; 
        int left = 0, right = nums.size() - 1;
        //(5)相当于掐头去尾
        if(nums[right] == nums[left])
        {
            //当要注意的时，始终保持left<right，防止[1,1,1,1,1,1]这种情况下一直--或者++
            while(nums[left] == nums[left+1] && left < right && left + 2<nums.size()){left++; }
            while(nums[right] == nums[right-1] && right > left && right - 2<nums.size()){right -- ;}
        }
        while(left + 1 < right)
        {
            int mid = left + (right-left)/2;
            cout<<"mid = "<<mid<<endl;
            //(1)
            if((nums[mid] <= nums[mid+1]) && (nums[mid] < nums[mid-1]))
            {
                return nums[mid];
            }
            //(2)
            else if(nums[mid] < nums[0])
            {
                right = mid;
            }
            //(3)
            else if(nums[mid] >= nums[0])
            {
                left = mid;
            }
        }
        return (nums[left]<nums[right])?nums[left]:nums[right];
    }
};