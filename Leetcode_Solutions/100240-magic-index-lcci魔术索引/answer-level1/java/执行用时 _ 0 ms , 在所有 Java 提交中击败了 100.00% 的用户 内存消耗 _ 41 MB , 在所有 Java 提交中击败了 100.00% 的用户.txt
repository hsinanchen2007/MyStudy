### 解题思路
这题挺简单的，从前往后，找到就结束循环，找不到就返回-1。

### 代码

```java
class Solution {
    public int findMagicIndex(int[] nums) {
        for(int i = 0;i<nums.length;i++) {
            if(nums[i]==i) {
                return i;
            }
        }
        return -1;
    }
}
```