### 解题思路
     * 利用数组1的尾部的空白位置，判断当前位置的两个数组哪个值比较大，
     *  将大的加入到数组的尾部，直到nums2数组的当前位置不大于0
### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int pos= m+n-1;

        while (n>0){
            if (m>0&&nums1[m-1]>nums2[n-1]){
                nums1[pos--]= nums1[--m];
                
            }else {
                nums1[pos--]= nums2[--n];
            }
        }
    }
}
```