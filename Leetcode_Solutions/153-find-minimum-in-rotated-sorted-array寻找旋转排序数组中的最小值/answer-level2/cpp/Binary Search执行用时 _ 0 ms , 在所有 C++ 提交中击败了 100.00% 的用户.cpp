```
class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int l = 0, h = nums.size() - 1;
        //从两头开始搜索
        while(l < h)
        {
            int mid = l + (h-l)/2;
            if(nums[mid] <= nums[h])  
            //若中间数小于右端数，说明中间数属于右边递增数组，只需把右边界h定于mid处
                h = mid;
            else
            //否则，中间数属于左边递增数组，只需把左边界l定于mid+1处
                l = mid + 1;
        }//当l == h时跳出循环
        return nums[h];
    }
};
```
