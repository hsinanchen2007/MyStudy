### 解题思路
使用异或的方法(XOR)发现只出现一次的数字。

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        int res = 0;
        for (int i = 0; i < nums.length; i++){
            res ^= nums[i];
        }
        return res;
    }
}
```