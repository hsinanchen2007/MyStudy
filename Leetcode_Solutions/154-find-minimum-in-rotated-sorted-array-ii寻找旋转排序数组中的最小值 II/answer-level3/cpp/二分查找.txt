与153类似。对于区间[i,j]，设k=(i+j)/2;若A[k]>A[j],转折点在(k,j]中，二分查找[k+1,j]；
若A[k]<A[i]，转折点在[i,k]中，二分查找[i,k]；否则，有两种情况：
1）A[k]==A[j]或者A[k]==A[i]，那么最小的在[i,j-1]或者[i+1,j]中，且一定在[i,j-1]中；
2）A[k]<A[j]或者A[k]>A[i]，那么最小的在[i,j-1]中。
两种情况合并，最小值一定在[i,j-1]中。
```
// Time O(logn), Space O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0;
        for(int k, j=nums.size()-1; i<j;){
            k=(i+j)/2;
            if(nums[k]>nums[j]) i=k+1;
            else if(nums[k]<nums[i]) j=k;
            else --j;
        }
        return nums[i];
    }
};
```
