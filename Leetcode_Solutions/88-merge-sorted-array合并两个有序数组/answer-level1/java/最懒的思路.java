### 解题思路
最懒的思路，放到一起
然后再进行排序

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for(int i=0;m<nums1.length;m++,i++){
            nums1[m] = nums2[i];
        }
        Arrays.sort(nums1);

    }
}
```