思路：
1，若待查找的元素刚好为序列的中间值，返回序列中间值的下标
2，若待查找的元素不是序列的中间值，则待查找的元素位于左子序列和右子序列中
3，对于递增的子序列，对其进行二分查找，对于非递增的子序列，对其进行递归操作。

```
class Solution {
public:
    int search(vector<int>& nums,int target){
        return mysearch(nums,0,nums.size()-1,target);
    }
    int mysearch(vector<int>& nums,int l,int r, int target) {
        
        if(l>r){
            return -1;
        }else{
            int mid = l+(r-l)/2;
            if(nums[mid] == target)
                return mid;
            else{
                int left=-1;
                int right = left;
                if(mid>l&&nums[l]<=nums[mid-1]){
                    left = bsearch(nums,l,mid-1,target);
                }else if(mid>l&&nums[l]>nums[mid-1]){
                    left = mysearch(nums,l,mid-1,target);
                }
                if(left>=0)
                    return left;
                if(mid<r&&nums[mid+1]<=nums[r]){
                    right = bsearch(nums,mid+1,r,target);
                }else if(mid<r&&nums[mid+1]>nums[r]){
                    right = mysearch(nums,mid+1,r,target);
                }
                if(right>=0)
                    return right;
            }
        }
        
        return -1;
    }
    
    int bsearch(vector<int> &nums,int l,int r,int target){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]>target){
                r = mid-1;
            }else if(nums[mid]<target){
                l = mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};
```
