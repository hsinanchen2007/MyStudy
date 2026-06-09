class Solution {
    public int findPairs(int[] nums, int k) {
        int i = 0;
        int j = 1;
        int target = 0;
        int temp = -10000;//有个测试数据第一个数据是-1，所一哈哈哈哈水一下
        Arrays.sort(nums);
        while(j<nums.length){
            if(nums[j] - nums[i]>k){
                i++;
                if(i==j){
                    j++;
                }
            }else if(nums[j] - nums[i] < k){
                j++;
            }else if(nums[j] - nums[i] == k&&nums[i]!=temp){
                temp = nums[i];
                i++;
                j++;
                target++;
            }else{
                i++;
                j++;
            }
        }
        return target;
    }
}