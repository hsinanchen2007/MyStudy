class Solution {
    public int missingNumber(int[] nums) {
<!-- 当nums ={0}时  确保返回值为 1 -->
        if(nums.length == 1 && nums[0] == 0){
            return 1;
        }
<!-- 当nums = {1,2}时  确保返回值为 0 -->
        if(nums[0] != 0){
            return 0;
        }
        int temp = 0;
<!-- 从索引为1的地方遍历数组 -->
        for(int i = 1;i<nums.length;i++){
<!-- 如果中间出现断层，则找到结果，跳出循环 -->
            if((nums[i]-nums[i-1]) != 1){
                temp = nums[i]-1;
                break;
            }else{
<!-- 找不到断层，就返回数组的最后一个值+1即可 -->
                temp = nums[i]+1;
            }
        }
        return temp;
    }
}