### 解题思路
题中要找的是大于n/2的数，先将数组排序，然后中间位置的数必定是要求的数，

### 代码

```java
import java.util.Arrays;
class Solution {
    public static int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
    }  
}
```