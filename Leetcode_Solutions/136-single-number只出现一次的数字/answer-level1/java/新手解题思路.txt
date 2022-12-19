先对数组进行排序，直接两两相比较（nums[0]和nums[1]比，nums[2]和nums[3]比），得到的第一对不相等的对子，取前一个数就是返回值。
`class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        int num=0;
        for(int i=1;i<nums.length;i=i+2){
            if(nums[i]!=nums[i-1]){
                num=i-1;     
                break;
            }
            else{
                num=nums.length-1;
            }
        }
                return nums[num];
    }
}

