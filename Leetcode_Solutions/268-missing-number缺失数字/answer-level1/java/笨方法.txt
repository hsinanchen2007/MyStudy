class Solution {
    public int missingNumber(int[] nums) {
        int i=0;
        Arrays.sort(nums);//先排序，再依次比较，耗时耗内存，别学我
        for(;i<nums.length;i++){
            if(i==nums[i]){
                continue;
            }else{
                break;
            }
        }
        return i;
    }
}