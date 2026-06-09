### 解题思路
此处撰写解题思路

### 代码

```java
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.stream.Collectors;
class Solution {
    public int majorityElement(int[] nums) {
       int length = nums.length;
        if (length == 0) {
            return 0;
        }
        Set<Integer> set = new HashSet<>(Arrays.stream(nums).boxed().collect(Collectors.toList()));
        int value = 0;
        for (int objSet : set) {
            int count = 0;
            for (Integer arrObj : nums) {
                if (objSet == arrObj) {
                    count++;
                }
            }
            if (new BigDecimal(count).compareTo(new BigDecimal(length).divide(new BigDecimal(2), 2, RoundingMode.HALF_UP)) > 0) {
                value = objSet;
            }
        }
        return value;
    }
}
```