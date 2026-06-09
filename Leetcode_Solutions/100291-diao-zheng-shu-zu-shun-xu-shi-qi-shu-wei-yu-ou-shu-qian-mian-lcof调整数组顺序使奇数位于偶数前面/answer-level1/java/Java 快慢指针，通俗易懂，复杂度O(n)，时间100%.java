class Solution {
    public int[] exchange(int[] nums) {
        if(nums.length==1) return nums;
        int ouFir = 0;
        int next = 0;
        int temp =0;
        while(next!=nums.length){
            if(nums[next]%2==0){
                next++;
            }else {
                temp = nums[next];
                nums[next] = nums[ouFir];
                nums[ouFir] = temp;
                ouFir++;
                next++;
            }
        }
        return nums;
    }
}