执行用时 :0 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :34.3 MB, 在所有 java 提交中击败了86.49%的用户
```
class Solution {
    public int rob(int[] nums) {
        if(nums == null || nums.length < 1)
            return 0;
        if(nums.length == 1)
            return nums[0];
        int num0 = 0;
        int num1 = nums[0];
        int num2 = nums[1];
        int max = Math.max(num1,num2);
        for(int i = 3; i <= nums.length; i++){
            int temp = Math.max(num0,num1)+nums[i-1];
            max = Math.max(max,temp);
            num0 = num1;
            num1 = num2;
            num2 = max;
        }
        return max;
    }
}
```
