### 解题思路
从后往前遍历。因为最终的数组长度肯定是m+n，越大的数越先固定它的位置，并且固定了就不会改动

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int r1 = m-1;
        int r2 = n-1;
        int curIdx = m + n - 1;

        while(r1 >= 0 && r2 >= 0){
            if(nums1[r1] >= nums2[r2]){
                nums1[curIdx] = nums1[r1];
                r1--;
            } else{
                nums1[curIdx] = nums2[r2];
                r2--;
            }
            curIdx--;
        }
        if(r1 == -1){
            System.arraycopy(nums2, 0, nums1, 0, r2+1);
        }
    }
}
```