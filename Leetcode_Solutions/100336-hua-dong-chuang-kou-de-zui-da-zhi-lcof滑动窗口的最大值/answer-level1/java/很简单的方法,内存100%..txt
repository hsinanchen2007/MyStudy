class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int l = nums.length;
        int a[] = new int[l-k+1];
        if(l==0) { return nums;}
        for(int i=0,j=k;j<l+1;i++,j++){
            int max=nums[i];
            for(int b=i;b<j;b++){
                if(nums[b] > max){
                    max=nums[b];
                }
            }
            a[i]=max;
        }
        return a;
    }
}