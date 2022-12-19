思路：用一个boolean数组保存每个数字是否出现过。
```
    public int missingNumber(int[] nums) {
        if (nums.length == 1) {
            return 1 - nums[0];
        }
        boolean[] booleans = new boolean[nums.length];
        for (int num : nums) {
            if (num != 0) {
                booleans[num-1] = true;
            }
        }
        for (int i = 0; i < booleans.length; i++) {
            if (!booleans[i]) {
                return i+1;
            }
        }
        return 0;
    }
```
