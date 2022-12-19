### 解题思路
1.汉明距离总和等于仍以对应位上汉明距离的和
2.对应位汉明距离和 = 对应位为0的个数  *  对应位为1的个数

### 代码

```java
class Solution {
    public int totalHammingDistance(int[] nums) {
        int len = nums.length;
        if (len <= 1)
            return 0;
        int max = 0;
        for (int item : nums) {
            if (item > max)
                max = item;
        }
        int count = 0;
        int tmp = 0;
        while ((1 << tmp) <= max) {
            int one = 0;
            int zero = 0;
            for (int i = 0; i < len; i++){
                if (nums[i] % 2 == 1)
                    one++;
                else
                    zero++;
                nums[i] = nums[i] >> 1;
            }
            tmp++;
            count += zero * one;
        }
        return count;
    }
}
```
