思路：遍历数组，遇到不是0，就和最后一个不是0的指针调换位置。

定义2个指针，一个i,用来遍历整个数组，一个lastNotZero 存放最后一个不是0的数字。

遍历数组，判断是否是0，如果不是0，则将当前与lastNotZero调换位置，lastNotZero++。确保lastNotZero 之前的永远不为0，这样最后所有的0都在最后了。
    
public static void moveZeroes(int[] nums) {
        int lastNotZero= 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                int tmp = nums[lastNotZero];
                nums[lastNotZero++] = nums[i];
                nums[i] = tmp;
            }
        }
    }
时间复杂度：O(N)
空间复杂度：O(1)