1. **整体思路是二分搜索**
2. 二分搜素的本质是在一次二分后选择性的筛选掉一半的不符合算法的有序部分，比如这道题之中二分一次后判断mid值大于数组的最右值吗如果大于即可证明左边部分是有序的,并且目标值在左边区间内就二分左边区间即可，如果mid值小于数组最右值说明右边部分是有序的，二分即可
3. 反之继续调用右边区间执行2操作，直到找到target;
```
class Solution {
public:
    int ta;
    int ans=-1;
    void se(vector<int>& nums,int l,int r){
        while(l<=r){
            int mid=(l+r)>>1;
            if(ta==nums[mid]){
                ans=mid;
               // return 0;
            }
            if(nums[mid]<ta)l=mid+1;
            else
                r=mid-1;
        }
        return ;
    }
    
    void ok(vector<int>& nums,int l,int r){
        
        if(l>r)return;
        int mid=(l+r)>>1;
        if(nums[mid]==ta){
            ans=mid;
            return ;
        }
        if(nums[mid]>nums[r]&&ta>=nums[l]&&ta<=nums[mid]){
            se(nums,l,mid-1);
            return ;
        }
        else if(nums[mid]>nums[r]&&!(ta>=nums[l]&&ta<=nums[mid])){
            ok(nums,mid+1,r);
        }
        else if(nums[mid]<nums[r]&&ta>=nums[mid+1]&&ta<=nums[r]){
            se(nums,mid+1,r);
            return ;
        }
        else if(nums[mid]<nums[r]&&!(ta>=nums[mid+1]&&ta<=nums[r])){
            ok(nums,l,mid-1);
        }
    }
    int search(vector<int>& nums, int target) {
        ta=target;
        if(nums.empty())return ans;
        ok(nums,0,nums.size()-1);
        return ans;
    }
};
```
