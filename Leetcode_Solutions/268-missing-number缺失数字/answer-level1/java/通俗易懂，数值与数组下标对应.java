    /**
     * 遍历每一位将数值为n的数放入nums[n-1]上，标记0出现的位置idx
     * idx+1即为缺失的数字。若没出现0，则返回0。时间复杂度O(n)
     * 例如：
     * 输入: [9,6,4,2,3,5,7,0,1]
     *       [1,6,4,2,3,5,7,0,9]
     *       [1,5,4,2,3,6,7,0,9]
     *       [1,3,4,2,5,6,7,0,9]
     *       [1,4,3,2,5,6,7,0,9]
     *       [1,2,3,4,5,6,7,0,9]
     * 返回 7+1 = 8
     */
    public int missingNumber(int[] nums) {
        int i = 0;
        int temp = Integer.MAX_VALUE;
        while (i<nums.length) {
            while (nums[i] != i+1) {
                if (nums[i] == 0) {
                    temp = i;
                    break;
                }
                swap(i, nums[i]-1, nums);
            }
            i += 1;
        }
        return temp == Integer.MAX_VALUE ? 0 : temp+1;
    }

    private void swap(int idx, int jdx, int[] nums) {
        int temp = nums[idx];
        nums[idx] = nums[jdx];
        nums[jdx] = temp;
    }