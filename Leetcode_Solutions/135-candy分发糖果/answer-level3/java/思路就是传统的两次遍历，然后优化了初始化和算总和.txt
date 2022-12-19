```
    public int candy(int[] ratings) {
        if (ratings.length <= 1) {
            return ratings.length;
        }
        int len = ratings.length;
        int[] nums = new int[len];
        //从前往后
        for (int i = 1; i < len; i++) {
            if (ratings[i] > ratings[i - 1]) {
                nums[i] = nums[i - 1] + 1;
            }
        }
        //从后往前
        int sum = nums[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && nums[i] <= nums[i + 1]) {
                nums[i] = nums[i + 1] + 1;
            }
            sum+= nums[i];
        }
        //每人最少发一个糖 所以要+len
        return sum + len;
    }
```