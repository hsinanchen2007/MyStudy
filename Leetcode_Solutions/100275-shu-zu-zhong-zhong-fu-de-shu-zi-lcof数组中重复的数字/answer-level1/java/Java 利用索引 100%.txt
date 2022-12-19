利用2个已知条件：
- 所有元素在n - 1以内；
- 数组自带的索引属性。

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        int cur = 0;
        while (cur < nums.length) {
            if (nums[cur] != cur) {
                if (nums[nums[cur]] == nums[cur]) {
                    return nums[cur];
                }
                // swap
                int tmp = nums[cur];
                nums[cur] = nums[tmp];
                nums[tmp] = tmp;
            } else {
                cur++;
            }
        }
        return -1;
    }
}
```