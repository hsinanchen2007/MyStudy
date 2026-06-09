### 解题思路
直接把第二个数组加到第一个数组 再排序

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
       for(int i=0;i<n;i++) {
			nums1[i+m]=nums2[i];
		}
		Arrays.sort(nums1);
        }
}
```