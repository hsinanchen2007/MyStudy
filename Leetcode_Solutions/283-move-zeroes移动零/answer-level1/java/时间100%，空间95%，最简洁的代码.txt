//定义两个指针变量，i用来往前探索，j用来保持 <=j 的数非0    

    class Solution {
        public void moveZeroes(int[] nums) {
            //定义两个指针变量，i用来往前探索，j用来保持 <=j 的数非0
            int j = -1;

            for(int i = 0; i < nums.length; i++){
                if(nums[i] != 0){
                    j++;
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;

                }
            }
        }
    }