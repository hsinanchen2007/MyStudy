class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        int i=1;
        if(nums.length<2){
            return nums[0];
        }
        if(nums[0]!=nums[1]){ //头
            return nums[0];
        }
        while(i<nums.length-1){
            //排序后一个元素既不等于他前面一个又不等于他后面一个则是唯一的
            if(nums[i-1]!=nums[i] && nums[i]!=nums[i+1]){
                return nums[i];
            }else{
                i++;
            }
        }
        return nums[nums.length-1]; //尾
    }
}