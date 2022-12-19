### 解题思路
该题有两个方法：
- 直接使用暴力破解
- 二分法

### 代码

```java
class Solution {
    public int minArray(int[] nums) {
        // 方法一：直接暴力破解；
        int min = nums[0];
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < min) {
                return nums[i];
            }
        }

        return nums[0];

        // 方法二：由于是两个递增的数组，可以使用二分法
        int i = 0;
        int j = nums.length - 1;
        while (i < j) {
            int m = (i + j) / 2;
            if (nums[m] < nums[j] ) {
                j = m;
            } else if (nums[m] > nums[j]) {
                i = m + 1;
            } else {
                j = j - 1;
            }
        }

        return nums[i];

    }
}
```