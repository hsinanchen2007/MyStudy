### 解题思路
先求出总和，然后不断左右减，如果存在返回i，如果不存在返回-1。
这类题目可以理解为有套路吗？如果没做过确实不太好想出来。

### 代码

```java
class Solution {
    public int pivotIndex(int[] nums) {
        int rightSum = 0;
        int leftSum = 0;
        for (int num : nums) {
            rightSum += num;
        }

        for (int i = 0; i < nums.length; i++) {
            leftSum += nums[i];
            if (rightSum == leftSum) {
                return i;
            } else {
                rightSum -= nums[i];
            }
        }
        return -1;
    }
}
```