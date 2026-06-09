只需要找出两种情况：
1. 三个正数且最大三个数；
2. 两个负数最小且一个整数最大 （或者两个负数最小，一个负数最大）
比较上面两种情况大小

**运行结果：**	解答成功:执行耗时:21 ms,击败了77.03% 的Java用户，内存消耗:39.6 MB,击败了97.27% 的Java用户

也可以不排序，就是找出这五个数 两种组合算大小。
```
import java.util.Arrays;

class Solution {
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        int l = nums.length;
        int sum = nums[l - 1] * nums[l - 2] * nums[l - 3];
        int sum1 = nums[0] * nums[1] * nums[l - 1];
        if (sum > sum1)
            return sum;
        else
            return sum1;
    }
}
```
