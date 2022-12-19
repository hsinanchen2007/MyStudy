找到缺失数字的左界
1.如果nums[0]!=0,则结果为0,排除左边界越界情况
2.常规情况
①如果nums[mid]>mid,说明左边缺失，使right = mid - 1
②如果nums[mid]==mid,说明右边缺失，使left = mid
③如果nums[mid]<mid,无这种情况
注意：要充分理解上述三种情况
①我们要找左边界，所以在情况②中，使left = mid,如果left = mid + 1所找的就不是左边界
②在求mid时，如果用(left + right)/2,会导致最后剩余两个数，跳不出循环，所以应当用(left + right + 1)/2,使用哪种，要仔细想想剩余两个数的极端情况
```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums[0]!=0)
            return 0;
        int left = 0,right = nums.size()-1;
        while(left<right){
            int mid = (left + right + 1) / 2;
            if(nums[mid]==mid)
                left = mid;
            else if(nums[mid]>mid)
                right = mid - 1;
        }
        return left+1;
    }
};
```

