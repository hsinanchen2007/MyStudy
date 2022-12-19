

class Solution {
    public int dominantIndex(int[] nums) {

        int max=-1,maxIndex=-1,maxSecond=-1;

        for (int i = 0; i < nums.length; i ++){
            if(nums[i] > max){
                maxSecond = max;
                max = nums[i];
                maxIndex = i;
            } else if(nums[i] > maxSecond){
                maxSecond = nums[i];
            }
        }
        if(max >= 2*maxSecond){
            return maxIndex;
        }
        return -1;
    }
}