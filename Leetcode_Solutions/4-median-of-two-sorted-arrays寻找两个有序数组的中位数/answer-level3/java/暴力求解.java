### 解题思路
在所有 Java 提交中击败了
82.41%的用户
内存消耗 :40.6 MB, 在所有 Java 提交中击败了98.75%
的用户

合并两个有序数组
求新数组的中位数

### 代码

```java
class Solution {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] hebing = new int[nums1.length + nums2.length];
        double result = 0;
        int n1 = 0, n2=0;
        if (nums1==null || nums2==null){
            if (nums1 ==null) hebing = nums2;
            if (nums2==null) hebing =nums1;
        }else {
            for (int i = 0; i < hebing.length; i++) {
                if (n1 < nums1.length && n2 < nums2.length) {
                    if (nums1[n1] < nums2[n2]){
                        hebing[i] = nums1[n1];
                        n1++;
                    }else {
                        hebing[i] = nums2[n2];
                        n2++;
                    }
                } else if (n1 < nums1.length) {
                    hebing[i] = nums1[n1];
                    n1++;
                } else if (n2 < nums2.length) {
                    hebing[i] = nums2[n2];
                    n2++;
                }
            }
        }
        

        if (hebing.length %2==0){
            result = (double)(hebing[hebing.length/2-1] + hebing[hebing.length/2])/2;
        }else {
            result =hebing[hebing.length/2];
        }
        return result;
    }
}
```