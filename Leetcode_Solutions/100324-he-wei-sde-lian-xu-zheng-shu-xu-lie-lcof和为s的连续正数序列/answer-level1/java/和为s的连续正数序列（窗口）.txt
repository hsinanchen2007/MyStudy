### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        if (target == 1) {
            return new int[][]{};
        }
        List<int[]> res = new ArrayList<>();
        int[] nums = new int[target];
        for (int i = 0; i < nums.length; i++) {
            nums[i] = i;
        }
        int l = 1, r = 2;

        while (l < r && r < nums.length) {
            int sum = (l + r) * (r - l + 1) / 2;
            if (sum == target) {
                res.add(Arrays.copyOfRange(nums, l, ++r));
            } else if (sum > target) {
                l++;
            } else {
                r++;
            }
        }
        return res.toArray(new int[0][]);
    }

}
```