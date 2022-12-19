### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int massage(int[] nums) {

        int length = nums.length;

        if (0 == length) {
            return 0;
        }

        int[] result = new int[length];

        for (int i = 0; i < length; i++) {
            if (0 == i) {
                result[i] = nums[i];
                continue;
            }

            if (1 == i) {
                result[i] = Math.max(nums[0], nums[1]);
                continue;
            }

            result[i] = Math.max(result[i - 1], result[i - 2] + nums[i]);

        }

        return result[length - 1];
    }
}
```