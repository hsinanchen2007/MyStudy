![屏幕快照 2019-11-04 11.57.51.png](https://pic.leetcode-cn.com/c6b6e02e08233932da685a50963021083f17ad9de084134e9cb5f4483508645f-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-11-04%2011.57.51.png)

```
    public int firstMissingPositive(int[] nums) {
        if( nums.length == 0) { return 1; }
        Arrays.sort(nums);
        int firstPositive = -1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] <= 0) { continue; }
            // if firstPositive is 1，i must bigger than 0
            if ( firstPositive != -1 && nums[i] - nums[i - 1] != 1 && nums[i - 1] != nums[i]) {
                return nums[i - 1] + 1;
            }
            // find the first positive
            // TODO the first one is 1 and discontinuous
            if ((i > 0 && nums[i - 1] <= 0 && nums[i] > 0) || i == 0) {
                if (nums[i] != 1) { return 1; }
                else { firstPositive = nums[i]; }
            }
        }
        // no positive or all positive in the array, so return 1 or the last one plus 1
        if (nums[nums.length -1] < 0) { return 1; }
        else { return nums[nums.length -1] + 1; }
    }
```
