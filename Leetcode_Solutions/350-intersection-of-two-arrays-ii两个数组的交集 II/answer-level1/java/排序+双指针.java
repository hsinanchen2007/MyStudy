### 解题思路
数组问题：排序+其他算法（双指针、二分法等）基本解决运行速度都比较可观

### 代码

```java
import java.util.*;
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int left1 = 0;
        int left2 = 0;
        int [] result = new int[nums1.length];
        int i =0;
        while (left1 <nums1.length && left2 <nums2.length) {
            if (nums1[left1] == nums2[left2]) {
                result[i] = nums1[left1];
                i++;
                left1++;
                left2++;
            } else if (nums1[left1] > nums2[left2]) {
                left2++;
            } else {
                left1++;
            }
        }
        return  Arrays.copyOf(result,i);       
    }
}
```