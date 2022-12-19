 public int findMaxConsecutiveOnes(int[] nums) {
         int count = 0;
        int max = Integer.MIN_VALUE;
        for (int num : nums) {
            if (num == 1) {
                count++;
            } else {
                if (max < count) {
                    max = count;
                }
                count = 0;
            }
        }
        return Math.max(count, max);
    }