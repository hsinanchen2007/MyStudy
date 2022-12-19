class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        //判断最小值的位置，最小值是分界点
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            int mid=l+r>>1;
            if(nums[mid]<=nums.back()) r=mid;
            else l=mid+1;
        }
        //判断target 是在哪一段
        if(target<=nums.back()) r=nums.size()-1;
        else l=0,r--;
        while(l<r)
        {
            int mid=l+r>>1;
            if(nums[mid]>=target) r=mid;
            else l=mid+1;
        }
        //判断是否相等
        if(nums[l]==target) return l;
        return -1;
    }
};