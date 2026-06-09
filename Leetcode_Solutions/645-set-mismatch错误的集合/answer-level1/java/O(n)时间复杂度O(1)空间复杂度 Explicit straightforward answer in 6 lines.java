```
class Solution {
    public int[] findErrorNums(int[] nums) {
        int sum = 0, dup = 0, len = nums.length;       
        for (int i = 0; i < len; ++i) {
            if (nums[Math.abs(nums[i]) - 1] > 0) nums[Math.abs(nums[i]) - 1] = -nums[Math.abs(nums[i]) - 1];
            else dup = Math.abs(nums[i]);
            sum += Math.abs(nums[i]);
        }
        return new int[]{dup, dup - (sum - (len * (len + 1)) / 2)};
    }
}
```

分析: 

    1. 对于寻找重复的元素:

        通过将nums[Math.abs(nums[i] - 1)]的元素置负:

            当某个nums[Math.abs(nums[i] - 1)]已经被置0时, nums[i]即为重复元素!

        例: 

            [4, 1, 3, 3] -->  [4, 1, 3, -3] --> [-4, 1, 3, -3] --> [-4, 1, -3, -3] --> 此时n == 3, 而nums[2]已经被置负, 所以3为重复元素!

    2. 对于寻找缺失的元素:

        重复的元素一定是由缺失的那个元素加或者减某个数而变得, 而加的数为:

            sum - (len * len + len) / 2

        其中: sum为给定nums的元素绝对值的和, len为数组长, (len * len + len) / 2为未缺失元素时应有的和.

结合1. 2. 即求和和求重复同时进行即可.