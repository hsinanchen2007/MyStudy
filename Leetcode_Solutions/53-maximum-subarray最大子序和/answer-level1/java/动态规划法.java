可以设定 f(n) 为第n个数时的最大和结果
那么对于f(n)来说，应该有这样的状态转移方程。
f(n) = max{f(n-1) + nums[n], nums[n], f(n-1)}
也就是n-1的上一个最大值 + num[n] 和num[n] ，f(n - 1)取最大值

java代码如下
 public int maxSubArray(int[] nums) {
        int max = nums[0];
        int f[] = new int[nums.length];
        f[0] = nums[0];
        for(int i = 1; i < nums.length; i++){
            f[i] = Math.max(f[i - 1] + nums[i], nums[i]);
            if(max < f[i]){
                max = f[i];
            } 
        }
        return max;
    }
很明显，上面的f[] 每次循环时，只取了上一个值，所以可以优化成一个值，优化如下

class Solution {
    public int maxSubArray(int[] nums) {
        int max = nums[0];
        int sum = nums[0];
        for(int i = 1; i < nums.length; i++){
           int temp = Math.max(sum + nums[i], nums[i]);
            max = Math.max(max, temp);
            sum = temp;
        }
        return max;
    }
}