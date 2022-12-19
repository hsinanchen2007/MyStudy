### 解题思路
这一题主要是因为nums1足够大，满足条件，所以可以直接在其中添加后进行排序即可

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
         int j = 0;
		 for (int i = 0; i < nums1.length; i++) {
			 if (nums1[i]==0 && j < n) {
				 nums1[i] = nums2[j];
				 j++;
			 }
		 }
         Arrays.sort(nums1);
    }
}
```