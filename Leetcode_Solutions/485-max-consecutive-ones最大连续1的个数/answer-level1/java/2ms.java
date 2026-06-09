  public int findMaxConsecutiveOnes(int[] nums) {

        int maxNums = Integer.MIN_VALUE;
        int tempMaxNums = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                tempMaxNums++;
            } else {
                if (tempMaxNums > maxNums) {
                    maxNums = tempMaxNums;
                }
                tempMaxNums = 0;
            }

        }
        if (tempMaxNums > maxNums) {
            maxNums = tempMaxNums;
        }

        return maxNums;
    }

![image.png](https://pic.leetcode-cn.com/dfb82698b0e5fd9b12b3d7c692b4f7982d803666b16b8fd3d87ea4f00084a56a-image.png)
