### 解题思路
pow()

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int num = (int)(Math.pow(10, n));
        int[] nums = new int[num-1];
        for (int i = 0; i < nums.length; i++) {
            nums[i] = i+1;
        }

        return nums;
    }
}
```