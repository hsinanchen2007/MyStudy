### 解题思路
我这个时间复杂度应该是o(n)吧

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] result = {-1, -1};
        boolean flag = true;
        for (int i = 0; i < nums.length; i++)
            if (nums[i] == target)
                if (flag) {
                    flag = false;
                    result[0] = i;
                    result[1] = i;
                } else
                    result[1] = Math.max(result[0], i);

        return result;
    }
}
```