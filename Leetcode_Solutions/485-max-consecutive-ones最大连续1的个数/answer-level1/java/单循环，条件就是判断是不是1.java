class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
    int lazy=0;
    int count=0;
    int maxCount=0;
        for (int i = 0; i < nums.length; i++) {
            if(nums[i]==1){
                count++;
                if(i==nums.length-1){
                    maxCount=Math.max(count,maxCount);//更新最大值
                }
            }
            else {
                maxCount=Math.max(count,maxCount);//更新最大值
                count=0;//清零
            }
            
        }
        return maxCount;
    }
}