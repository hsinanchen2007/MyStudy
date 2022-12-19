双指针：i用来探索，j用来保持 <=j 的元素都不重复

    class Solution {
        public int removeDuplicates(int[] nums) {
            //双指针：i用来探索，j用来保持 <=j 的元素都不重复
            int j = 0;
            for(int i = 0; i < nums.length; i++){
                //如果i,j所指元素不相等，j元素加1，同时将i所指元素赋给它
                if(nums[i] != nums[j])
                    nums[++j] = nums[i];  
            }
            return j + 1;
        }
    }