``` C++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int low=0,high=nums.size()-1;
        while(low<=high)//注意为小于等于，否则一个元素时出错
        {
            int mid=(low+high)/2;
            if(nums[mid]>target)
                high=mid-1;//注意要减1
            else if(nums[mid]<target)
                low=mid+1;//注意要加1
            else
                return mid;
        }
        return -1;
    }
};
```