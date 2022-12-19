### 解题思路
不符合题意，这个方法是（m + n）时间复杂度，要用二分法，接下来更新。

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int[] temp = new int[m + n];
        int i = 0, j = 0;
        int index = 0;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                temp[index++] = nums1[i++];
            } else {
                temp[index++] = nums2[j++];
            }
        }

        while(i < m) {
            temp[index++] = nums1[i++];
        }

        while(j < n) {
            temp[index++] = nums2[j++];
        }
        
        return (m + n) % 2 == 1 ? temp[(m + n) / 2] : (temp[(m + n) / 2 - 1] + temp[(m + n) / 2]) * 1.0 / 2;
    }
}
```