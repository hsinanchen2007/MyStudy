### 解题思路
思路和三数之和一样，最后都转化成了双数和问题，经典解法就是双指针了。
`O(n^3)复杂度`偏暴力，不过暂时也没想到更优的解法...稍微还能做的应该是常数上的优化了，在for loop的时候加几次判断。
### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        if (nums == null || nums.length < 4) {
            return res;
        }
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 3; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                // 转化为ThreeSum
                for (int j = i + 1; j < nums.length - 2; j++) {
                    if (j == i + 1 || nums[j] != nums[j - 1]) {
                        // 转化为TwoSum问题
                        int begin = j + 1, end = nums.length - 1;
                        int newTarget = target - nums[i] - nums[j];
                        while (begin < end) {
                            int temp = nums[begin] + nums[end];
                            if (temp == newTarget) {
                                res.add(Arrays.asList(nums[i], nums[j], nums[begin], nums[end]));
                                // 去重
                                while (begin < end && nums[begin] == nums[begin + 1]) begin++;
                                while (begin < end && nums[end] == nums[end - 1]) end--;
                                begin++;
                                end--;
                            } else if (temp > newTarget) {
                                end--;
                            } else {
                                begin++;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
}
```