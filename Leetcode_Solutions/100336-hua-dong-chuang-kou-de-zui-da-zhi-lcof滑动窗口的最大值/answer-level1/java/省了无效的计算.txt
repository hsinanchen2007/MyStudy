```
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int l=0,r=k-1;
        int len=nums.length;
        if(len==0||k==1)return nums;
        int max=max(nums,l,r);//滑动窗口内最大值的位次
        int[] res=new int[len-k+1];
        res[0]=nums[max];
        l++;
        r++;
        for(;r<len;l++,r++){
            if(nums[r]>=nums[max]){
                max=r;
            }else if(max<l){
                max=max(nums,l,r);
            }
            //max=max(nums,l,r);//滑动窗口内最大值的位次
            res[r-k+1]=nums[max];
        }
        return res;
    }
    static int max(int[] nums,int l,int r){
        int max=l;
        for(int i=l;i<=r;i++){
            if(nums[i]>nums[max])max=i;
        }
        return max;
    }
}
```
