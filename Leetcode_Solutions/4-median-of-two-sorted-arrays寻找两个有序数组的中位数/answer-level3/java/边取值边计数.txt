### 解题思路
![截屏2020-03-06上午9.55.13.png](https://pic.leetcode-cn.com/1291319fd457baded39fb8529d2e1b99d13b526648ed3c873b070eb4a93268cb-%E6%88%AA%E5%B1%8F2020-03-06%E4%B8%8A%E5%8D%889.55.13.png)


### 代码

```java
import java.util.ArrayList;

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length == 0) {
            return nums2.length % 2 == 0 ? (nums2[nums2.length/2]+nums2[nums2.length/2-1])/2.0 : nums2[nums2.length/2];
        }else if (nums2.length == 0) {
            return nums1.length % 2 == 0 ? (nums1[nums1.length/2]+nums1[nums1.length/2-1])/2.0 : nums1[nums1.length/2];
        }
        if(nums1.length > nums2.length) {
            int[] temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        int mid = (nums1.length + nums2.length + 1) / 2;
        int position = 0,i = 0,j = 0,res = 0;
        while(position < mid) {
            if(nums1[i] <= nums2[j]) {
                if (i < nums1.length) {
                    res = nums1[i];
                    if (i != nums1.length-1)
                        i++;
                    else
                        nums1[i] = 999999;
                    position++;
                } else {
                    res = nums2[j];
                    j++;
                    position++;
                }
            }else{
                res = nums2[j];
                if (j != nums2.length-1)
                    j++;
                else
                    nums2[j] = 999999;
                position ++;
            }
        }
        if((nums1.length + nums2.length) % 2 != 0) {
            return res;
        }else{
            if (nums1[i] < nums2[j]) {
                res += nums1[i];
                return res/2.0;
            } else {
                res += nums2[j];
                return res/2.0;
            }
        }
    }

}
```