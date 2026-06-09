### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if ((nums == null) || (nums.length == 0)) {
            return 0;
        }
        int[] db = new int[nums.length];
        db[0] = 1;
        int max = 1;
        for (int i = 1; i < nums.length; i++) {
            int maxval = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    maxval = Math.max(maxval, db[j]);
                }
            }
            db[i] = maxval + 1;
            max = Math.max(max, db[i]);
        }

        return max;
    }
}
```