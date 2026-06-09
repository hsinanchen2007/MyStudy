### 解题思路
![image.png](https://pic.leetcode-cn.com/cfdf3ebd4565b46eb2ba0492e30e8799bc708b4fc7134eeb10848ffcc9684650-image.png)

### 代码

```java
class Solution {
    public int findPairs(int[] nums, int k) {
        if (k < 0) {
            return 0;
        }
        int count = 0;
        Arrays.sort(nums);
        int start = 0;
        Integer pre = null;
        for (int i = 1; i < nums.length; i++) {
            if ((pre != null && pre == nums[start]) || nums[i] - nums[start] > k) {
                start++;
                if (start != i) {
                    i--;
                }
            } else if (nums[i] - nums[start] == k) {
                pre = nums[start];
                start++;
                count++;
            }
        }
        return count;
    }
}
```