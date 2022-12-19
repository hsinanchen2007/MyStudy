### 解题思路
简单的加减法。

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int size = nums.length;
        int ideal_sum = size * (1 + size) / 2;
        for (int i = 0; i < size; i++){
            ideal_sum -= nums[i];
        }
        return ideal_sum;
    }
}
```