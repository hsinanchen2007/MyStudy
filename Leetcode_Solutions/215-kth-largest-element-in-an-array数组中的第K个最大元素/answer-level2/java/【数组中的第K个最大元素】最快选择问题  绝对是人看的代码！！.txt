```
class Solution {
    public int findKthLargest(int[] nums, int k) {
        return sort1(nums,0,nums.length-1,k);
    }
    
    public int sort1(int[] nums,int l,int r,int k){
        if(l<=r){
        int i=l,j=r;
        int x=nums[l];
        while(i<j){
            while(i<j&&nums[j]<=x)
                j--;
            if(i<j)
                nums[i++]=nums[j];
            while(i<j&&nums[i]>=x)
                i++;
            if(i<j)
                nums[j--]=nums[i];
                
        }
            nums[i]=x;
            if(k==i-l+1)
                return nums[i];
            else if(k>i-l+1)
                return sort1(nums,i+1,r,k-(i-l)-1);
            else 
                return sort1(nums,l,i-1,k);
        }
        return -1;
    }
}
```