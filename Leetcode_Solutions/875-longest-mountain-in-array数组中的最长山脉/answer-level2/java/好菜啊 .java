class Solution {
        public int longestMountain(int nums[]) {
    	 int len = nums.length;
    	 int ret=0;
    	 int left =0,right =0;
    	 for(int i =1;i<len-1;i++) {
    		 if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) {
    			 left = i-1;
    		     right =i+1;
    		     while(left>0&&nums[left]>nums[left-1])
        			 left--;
        		 while(right<len-1&&nums[right]>nums[right+1])
        			 right++;
        		 ret = Math.max(ret, right-left+1);
    		 }else {
    			 if(i==len-2) return ret ==1? 0:ret;
    		 }
    		 
    	 }
    	 return ret;
     }
}