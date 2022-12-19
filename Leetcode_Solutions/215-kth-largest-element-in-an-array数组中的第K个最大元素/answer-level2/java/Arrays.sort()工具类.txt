### 解题思路
此处撰写解题思路
Arrays.sort()工具类，降序排序
### 代码

```java
import java.util.*;
class Solution {
    public int findKthLargest(int[] nums, int k) {
        Integer[] ints = new Integer[nums.length];
        int x = 0;
        for(int i:nums)
            ints[x++] = i;
        Arrays.sort(ints,(Integer t1,Integer t2) -> t2 - t1);
        return ints[k-1];
    }
}
```