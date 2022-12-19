### 解题思路
一看就是异或，哈哈哈哈
### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        for(int i=1;i<nums.length;i++){
            nums[0]^=nums[i];
        }
        return nums[0];
    }
}
```