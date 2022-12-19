```
class Solution 
{
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int l = 0;
        int h = nums.size() - 1;
        //二分查找
        while(l < h)
        {
            int mid = l + (h - l)/2;
            if(mid % 2 == 1)               //防止mid是奇数，是的话则左移一位
                mid--;
            if(nums[mid] == nums[mid+1])   //说明目标数在[mid+2,h]
                l = mid + 2;
            else                           //否则目标数在[l,mid]
                h = mid;
        } 
        return nums[l];   
    }
};
```
