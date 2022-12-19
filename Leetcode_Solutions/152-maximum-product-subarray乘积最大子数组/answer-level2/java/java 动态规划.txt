```
 int[][] result = new int[nums.length][2];
        result[0][0] = nums[0];
        result[0][1] = nums[0];
        int dpResult = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int first = result[i - 1][0] * nums[i];
            int second = result[i - 1][1] * nums[i];
            result[i][0] = Math.max(Math.max(first, second), nums[i]);
            result[i][1] = Math.min(Math.min(first, second), nums[i]);
            dpResult = Math.max(dpResult, result[i][0]);
        }
        return dpResult;
```
