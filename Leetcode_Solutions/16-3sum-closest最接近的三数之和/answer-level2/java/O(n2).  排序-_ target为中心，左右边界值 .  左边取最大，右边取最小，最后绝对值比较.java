**16. 最接近的三数之和**

class Solution {
    
     public  int threeSumClosest(int[] nums, int target) {
         
        Arrays.sort(nums);

        int leftEdge = nums[0]+ nums[1]+ nums[2];
        if (leftEdge >= target) return leftEdge;

        int rightEdge = nums[nums.length - 3] + nums[nums.length - 2] + nums[nums.length - 1];
        if (rightEdge <= target) return rightEdge;

        
        for (int i = 0; i < nums.length - 2; i++) {
            
            int l = i + 1;
            int r = nums.length -1 ;
            
            while ( l < r ) {
                int currSum = nums[i] + nums[l] + nums[r];
                if (currSum == target) return currSum;
                
                if( currSum < target){
                    if(currSum > leftEdge){
                        leftEdge = currSum;
                    }
                    l++;
                }else{
                    if( currSum < rightEdge){
                        rightEdge = currSum;
                    }
                    r --;

                }
            }

        }

        int leftDis = Math.abs(leftEdge - target);
        int rightDis = Math.abs(rightEdge - target);
        return leftDis > rightDis ? rightEdge : leftEdge;
     }


}