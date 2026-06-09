只求第三大的数，不需要整体顺序，因此不需要排序

遍历找出最大的，然后从非最大数开始遍历，找出第二大的，类似流程就可以找出第三大的

代码：
```
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)
            return nums[0];
        else if(len == 2)
            return nums[0] > nums[1] ? nums[0] : nums[1];
        else {
            int max1 = nums[0];
            for(int i = 1 ; i < len ; i++)
                max1 = nums[i] > max1 ? nums[i] : max1;
            int begin = 0;
            for(; begin < len; begin++) {
                if(nums[begin] != max1)
                    break;
            }
            if(begin == len)
                return max1;
            int max2 = nums[begin];
            for(; begin < len ; begin++) {
                if(nums[begin] > max2 && nums[begin] != max1)
                    max2 = nums[begin];
            }
            begin = 0;
            for(; begin < len; begin++) {
                if(nums[begin] != max1 && nums[begin] != max2)
                    break;
            }
            if(begin == len)
                return max1;
            int max3 = nums[begin];
            for(; begin < len ; begin++) {
                if(nums[begin] > max3 && nums[begin] != max1 && nums[begin] != max2)
                    max3 = nums[begin];
            }
            return max3;
        } 
    }
};
```
