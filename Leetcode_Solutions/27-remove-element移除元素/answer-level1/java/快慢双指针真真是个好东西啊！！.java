### 思路一

快慢双指针，这种思路在移除元素较多时更适合使用

### 代码：

时间复杂度O(n)，空间复杂度O(1)

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int count = 0;
        for (int x : nums) {
            if (x != val) {
                nums[count++] = x;
            }
        }
        return count;
    }
}
```

### Result：

Runtime：0ms

Your runtime beats 100% of java submissions.