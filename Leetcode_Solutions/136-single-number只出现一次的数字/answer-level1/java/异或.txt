### 解题思路
很巧妙的做法，异或的性质，a ^ a = 0，a ^ 0 = a，a ^ a ^ a = a，所以，我们对整个数组的元素都做一遍异或，这样所有出现两次的元素都异或变成了0，只剩下那个出现一次的元素的值

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        int res = nums[0];
        for (int i = 1; i < nums.length; i++) {
            res ^= nums[i];
        }
        return res;
    }
}
```