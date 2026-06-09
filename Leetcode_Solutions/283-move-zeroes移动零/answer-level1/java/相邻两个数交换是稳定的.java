    
    class Solution {
        public void moveZeroes(int[] nums) {
            int left = -1, right = -1;
            int i = 0;
            for(;i < nums.length;i++) {
                if(nums[i] == 0) {
                    left = i;
                    right = i++;
                    break;
                }
            }
            if(left == -1) {
                return;
            }
            for(;i < nums.length;i++) {
                if(nums[i] == 0) {
                    right++;
                }else {
                    int temp = nums[left];
                    nums[left] = nums[i];
                    nums[i] = temp;
                    left++;
                    right++;
                }
            }
        }
    }