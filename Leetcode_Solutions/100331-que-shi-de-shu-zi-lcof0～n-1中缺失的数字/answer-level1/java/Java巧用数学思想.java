### 解题思路 
假设缺失的数字为x,则数组nums中所有元素之和sum1再加上x，不就是0到n-1的等差数列求和吗？
- 即x = sum2 - sum1

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int sum1 = 0;
        int sum2 = 0;
        int n = nums.length + 1;
        for(int i = 0;i < nums.length;i++){
            sum1 += nums[i];
        }
        sum2 = n * (n - 1) >>> 1;
        return sum2 - sum1;
    }
}
```