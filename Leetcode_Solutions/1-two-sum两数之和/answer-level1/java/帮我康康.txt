class Solution {
    public int[] twoSum(int[] nums, int target) {
        int y = nums.length-1 ;
        for(int a = 0 ; a<y;a++){
            for(int z = a+1;z<y+1;z++){
                if(nums[a]+nums[z]==target){
                  return new int [] {a,z};
                }
            }
        }
        return new int [] {0,0};
    }
}
各位大佬帮我再优化优化