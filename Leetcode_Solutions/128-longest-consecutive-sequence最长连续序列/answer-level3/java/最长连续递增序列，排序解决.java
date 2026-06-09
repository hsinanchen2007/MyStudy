### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length ==0) {
            return 0;
        }
        Arrays.sort(nums);
        int curLength = 1;
        int resLength = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i-1]) {
                continue;
            }
            if (nums[i] == nums[i-1]+1) {
                curLength += 1;
                continue;
            }
            resLength = Math.max(curLength,resLength);
            curLength = 1;
        }
        resLength = Math.max(curLength,resLength);
        return resLength;
    }
}
```