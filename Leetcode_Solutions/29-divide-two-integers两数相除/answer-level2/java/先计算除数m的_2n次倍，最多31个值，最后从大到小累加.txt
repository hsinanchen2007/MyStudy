### 解题思路
    先计算除数m的*2n次倍。最多31个值，最后从大到小累加
    如 901/3. 则 m*2n
    依次是3,6,12,24,48,96,192,384,768
    倍数是1,2,  4,  8,16,32,64,128,256(即:1<<n)
    901 = 768 + 96 + 24+12+1
    故901/3 =  256 +32+ 8+4 = 300
### 代码

```java
class Solution {
    public int divide(int dividend, int divisor) {
        if (divisor == 1) {
            return dividend;
        }
        if (divisor == 0 || dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        if (divisor == -1) {
            return -dividend;
        }

        boolean positive = (dividend ^ divisor) >= 0;
        //按负数运算
        dividend = dividend < 0 ? dividend : -dividend;
        divisor = divisor < 0 ? divisor : -divisor;

        int[] nums = new int[31];
        nums[0] = divisor;
        int max = dividend >> 1;
        for (int i = 1; i < nums.length && nums[i - 1] >= max; i++) {
            nums[i] = nums[i - 1] << 1;
        }
        int count = 0;
        for (int i = nums.length - 1; i >= 0; i--) {
            if (nums[i] != 0 && dividend <= nums[i]) {
                count += 1 << i;
                dividend -= nums[i];
            }
        }
        return positive ? count : -count;
    }
}
```