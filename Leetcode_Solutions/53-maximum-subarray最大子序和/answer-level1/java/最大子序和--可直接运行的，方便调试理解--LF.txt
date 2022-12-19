```
package ZJM_53_最大子序和;

public class Main {
    public static void main(String[] args) {
        int[] nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int[] nums2 = {-1};
        int[] nums3 = {-2, -1};

        Solution solution = new Solution();
        System.out.println(solution.maxSubArray(nums1));
        System.out.println(solution.maxSubArray(nums2));
        System.out.println(solution.maxSubArray(nums3));
    }
}

class Solution {
    public int maxSubArray(int[] nums) {
        int temp = 0;
        int max = nums[0];

        for (int i = 0; i < nums.length; i++) {
            if (temp > 0) {
                temp += nums[i];

            } else {
                temp = nums[i];
            }
            if (temp > max) {
                max = temp;
            }
        }

        return max;
    }
}

/**
 * 本题我的思路是起始为负值的元素直接排除，元素累加为负的也不是最大子序，
 * 定义一个实时的累加值和一个最大值，当累加值为负时归零(也就是从当前数开始）重新开始累加，
 * 当累加值大于最大值时将累加值赋值给最大值
 */

```
