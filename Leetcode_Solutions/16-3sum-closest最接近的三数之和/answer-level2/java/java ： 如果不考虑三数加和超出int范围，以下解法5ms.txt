
双指针夹逼，贪心并记录当前最佳结果

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        if(nums == null || nums.length  < 3) {
            return 0;
        }
        int size = nums.length;
        int tempResult = 0;
        int tempCompa = Integer.MAX_VALUE;
        Arrays.sort(nums);
        
        for(int i=0; i< size -2;i++) {
            int j = i+1;
            int k = size -1;
            while(j < k) {
                int tempSum = nums[i] + nums[j] + nums[k];
                
                if(tempSum == target){
                   return target; 
                } else if(tempSum > target) {
                    if(tempSum - target < tempCompa){
                        tempResult = tempSum;
                        tempCompa = tempSum - target;
                        k--;
                    } else {
                        k--;
                    }
                    
                } else {
                    if(target - tempSum < tempCompa) {
                        tempResult = tempSum;
                        tempCompa = target - tempSum;
                        j++;
                    } else {
                        j++;
                    }
                }
            }
        }
        return tempResult;
    }
}