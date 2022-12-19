### 解题思路
导包的解法

### 代码

```java
import java.util.Arrays;

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
            if(nums1==null&&nums2==null){
                return -1.0;
            }
            double result = 0;
            int mid = 0;
            int len = nums1.length+nums2.length;
            int[] nums3 = new int[len];
            System.arraycopy(nums1,0,nums3,0,nums1.length);
            System.arraycopy(nums2,0,nums3,nums1.length,nums2.length);
            Arrays.sort(nums3);
            mid = len/2;
            if(len%2==0){
              result = (double)(nums3[mid]+nums3[mid-1])/2;
              return result;
            }else{
                result = nums3[mid];
                return result;
            }
    }
}
```