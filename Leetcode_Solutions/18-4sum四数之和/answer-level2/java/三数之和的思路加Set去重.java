### 解题思路
生搬硬套三数之和的思路，只是在外面再加一层循环。用到了Set去重，最后用stream赋值给list

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> lists = new ArrayList<>();
        HashSet<List<Integer>> set = new HashSet<>();
        if (nums.length < 4 || nums == null)
            return lists;
        Arrays.sort(nums);
        int temp = target;
        for (int i = 0; i < nums.length - 3; i++) {
            target = target - nums[i];
            int len = nums.length;
            for (int j = i + 1; j < len; j++) {
                int L = j + 1;
                int R = len - 1;
                while (L < R) {
                    int sum = nums[j] + nums[L] + nums[R];
                    if (sum == target) {
                        set.add(Arrays.asList(nums[i], nums[j], nums[L], nums[R]));
                        R--;
                        L++;
                    }
                    if (sum > target) R--;
                    if (sum < target) L++;
                }
            }
            target = temp;
        }
        set.stream().forEach(n -> lists.add(n));
        return lists;
    }
}
```