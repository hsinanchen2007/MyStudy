因为对于有序数组进行了旋转，但是旋转的节点未知，我们可以对一个小的例子列出所有的旋转情况进行观察，可以发现第一次二分之后，要么左边是有序的，要么右边是有序的，我们在有序的半段里进行查找，要不就放在非有序的段落进行查找，如下：
(本题能用二分的原因在于无论怎样旋转，可以保证左边有序或者右边有序，剩下的半段中部分有序)

```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target) return m;
            if(nums[m]<nums[r]){
                if(nums[m]<target && target<=nums[r]) l=m+1;
                else r=m-1;
            }else{
                if(nums[l]<=target && target<nums[m]) r=m-1;
                else l=m+1;
            }
        }
        return -1;
    }
};
```