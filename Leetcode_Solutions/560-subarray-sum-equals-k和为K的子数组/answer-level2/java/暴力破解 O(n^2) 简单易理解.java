class Solution {
    public int subarraySum(int[] nums, int k) {
        int flag=0;
        int count=0;
        int res=0;
        while(flag<nums.length){
            for(int i=flag;i<nums.length;i++){
                res=res+nums[i];
                if(res==k){
                    count++;
                }
            }
            flag++;
            res=0;
        }
        return count;
    }
}