### 解题思路
思路与“打家劫舍”这题还是一样的，只是要维护两个数据：一是包含第一家的最大收益，二是不包含第一家的最大收益。

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        int profitFromFirst = nums[0];
        int previousProfitFromFirst = profitFromFirst;
        if (n == 1) return profitFromFirst;
        int profitWithoutFirst = nums[1];
        int previousProfitWithoutFirst = 0;
        for (int i = 2; i < n; i++) {
            int num = nums[i];
            int max;
            if (i != n - 1) {
                max = Math.max(profitFromFirst, previousProfitFromFirst + num);
                previousProfitFromFirst = profitFromFirst;
                profitFromFirst = max;
            }
            max = Math.max(profitWithoutFirst, previousProfitWithoutFirst + num);
            previousProfitWithoutFirst = profitWithoutFirst;
            profitWithoutFirst = max;
        }
        return Math.max(profitFromFirst, profitWithoutFirst);
    }
}
```