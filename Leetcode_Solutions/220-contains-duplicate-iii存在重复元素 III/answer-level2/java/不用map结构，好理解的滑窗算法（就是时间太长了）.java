要点：1.（投机取巧地）设置成double防止溢出；2.动态滑窗
比不上大神的算法，但是很好理解，不用map结构

class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        
        int length = nums.length;
        if(k>=length){
            k = length-1;
        }
        
        for(int i=0; i<length-1; i++){
            for(int index=1; index<=k; index++){
            if(Math.abs((double)nums[i+index] - (double)nums[i]) <= t){
                return true;
                }
            }
            if(length-i-1<=k){k--;}
            
        }   
        return false;
    }
}