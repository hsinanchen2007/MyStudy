执行用时 :1 ms, 在所有 Java 提交中击败了99.18%的用户
内存消耗 :37.6 MB, 在所有 Java 提交中击败了76.39%的用户

### 解题思路
三次循环，分别找出最大，第二大，第三大的数字。

### 代码

```java
class Solution {
    public int thirdMax(int[] nums) {
        int max = 0;
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        int secondMax = Integer.MIN_VALUE;
        boolean a = false;
        for (int i = 0; i < len; i++) {
            if (nums[i] >= secondMax && nums[i] < max) {
                secondMax = nums[i];
                a = true;
            }
        }
        if (!a) {
            return max;
        }
        int thirdMax = Integer.MIN_VALUE;
        boolean b = false;
        for (int i = 0; i < len; i++) {
            if (nums[i] >= thirdMax && nums[i] < secondMax) {
                thirdMax = nums[i];
                b = true;
            }
        }
        if (!b) {
            return max;
        }
        return thirdMax;
    }
}
```