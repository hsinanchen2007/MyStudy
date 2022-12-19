![算法_20191123.jpg](https://pic.leetcode-cn.com/359af068bea930e0e9265ef79191dc0d20f4949496ff67911672ad927ecf083d-%E7%AE%97%E6%B3%95_20191123.jpg)

```
class Solution {
    public boolean canPartition(int[] nums) {

        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        //和为奇数，肯定不能分割为两个和相等的子集
        if (sum % 2 != 0) {
            return false;
        }
        sum /= 2;

        //将数组做降序排序，是为了可以进行剪支，避免无用的查找
        Arrays.sort(nums);
        reverse(nums);

        return canPartition(nums, sum, 0);
    }
    //翻转数组
    public void reverse(int[] data) {
        for (int left = 0, right = data.length - 1; left < right; left++, right--) {
            // swap the values at the left and right indices
            int temp = data[left];
            data[left] = data[right];
            data[right] = temp;
        }
    }

    private boolean canPartition(int[] nums, int sum, int index) {

        if (index >= nums.length || nums[index] > sum) {
            return false;
        }

        if (nums[index] == sum) {
            return true;
        }
        //对于数组每个元素，都有选择和不选择两种可能。
        return canPartition(nums, sum - nums[index], index + 1)||canPartition(nums, sum, index + 1) ;
    }
}
```
