### 解题思路
维护两个数min和max，一个向最小追求，一个向最大追求。为什么要维护min呢？因为下一个数如果是负的，一乘上去立马就是正的了，可能就成为max了。遍历时考虑如何延续min和max。如果碰到一个负数，看看这个负数和min能不能相乘得到一个更大的数，如果可以，max就能延续，否则，max就断了，只能从这个数开始。如果碰到一个正数，看看这个正数能不能和max相乘得到一个更小的数，如果可以，min就能延续，否则，min就断了，只能从这个数开始。

### 代码

```java
class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int min = 0;
        int max = 0;
        int maxProduct = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            int afterMin, afterMax;
            int num = nums[i];
            if (min == 0) {
                afterMin = num;
            } else {
                int product = num < 0 ? max * num : min * num;
                afterMin = Math.min(product, num);
            }
            if (max == 0) {
                afterMax = num;
            } else {
                int product = num > 0 ? max * num : min * num;
                afterMax = Math.max(product, num);
            }
            min = afterMin;
            max = afterMax;
            if (max > maxProduct) {
                maxProduct = max;
            }
        }
        return maxProduct;
    }
}
```