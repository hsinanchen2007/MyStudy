执行用时 :0 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :34.3 MB, 在所有 java 提交中击败了87.44%的用户
```
class Solution {
    public int rob(int[] nums) {
        if(nums == null || nums.length < 1)
            return 0;
        if(nums.length == 1)
            return nums[0];
        if(nums.length == 2)
            return Math.max(nums[0],nums[1]);
        return Math.max(getResult(nums, 0, nums.length-1), getResult(nums, 1, nums.length));
    }
    public int getResult(int[] nums, int start, int length){
        int num0 = 0;
        int num1 = nums[start];
        int num2 = nums[start+1];
        int max = 0;
        if(length-start == 2)
            return Math.max(num1,num2);
        for(int i = start+2; i < length; i++){
            int temp = Math.max(num0, num1)+nums[i];
            max = Math.max(max,temp);
            num0 = num1;
            num1 = num2;
            num2 = temp;
        }
        return max;
    }
}
```
