### 解题思路
思路就是，剩余数字为偶数的话，一定赢
若一开始xor的结果不是0，说明数组里面一定有数字不是成对出现的，那么最优解法肯定是移除掉单个出现的数字直到数组里面所有数字都是成对出现的（也就是偶数情况）
### 代码

```java
class Solution {
    public boolean xorGame(int[] nums) {
        int xor = 0;
        for (int i = 0; i < nums.length; i ++) {
            xor ^= nums[i];
        }
        return xor == 0 || nums.length % 2 == 0;
    }
}
```