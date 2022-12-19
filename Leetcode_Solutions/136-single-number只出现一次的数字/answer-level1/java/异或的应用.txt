### 解题思路
- 异或操作，相同为0，不同为1。与0异或结果为其本身。
- 异或满足交换律、结合律

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        int res = 0;
        for(int i = 0; i < nums.length; i++){
            res ^= nums[i];
        }
        return res;
    }
}
```