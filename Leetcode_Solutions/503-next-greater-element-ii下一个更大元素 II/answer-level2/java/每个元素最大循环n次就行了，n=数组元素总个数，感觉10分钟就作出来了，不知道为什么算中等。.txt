class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int len =nums.length;
        int [] ret = new int [nums.length];
        int i,j,k;
        for(i=0;i<len;i++){
            j=i+1;
            k=len;
            while(k>0){
                if(j==len){
                    j=0;
                }
                if(nums[j]>nums[i]){
                    ret[i]=nums[j];
                    break;
                }
                j++;
                k--;
            }
            if(k==0){
                ret[i]=-1;
            }
        }
        return ret ;
        
    }
}