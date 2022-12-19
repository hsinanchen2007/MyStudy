### 解题思路
此处撰写解题思路
将nums1元素整体后移nums2.length个长度，然后双指针比较移后的nums1和nums2即可
### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
		int n1 = n, n2 = 0;
		for (int i = m + n - 1; i >= n; i--) {
			nums1[i] = nums1[i - n]; 
		}
		for (int i = 0; i < m + n; i++) {
			if(n1 >= m + n) {
				nums1[i] = nums2[n2];
				n2++;
				continue;
			}
			if(n2 >= n) {
				nums1[i] = nums1[n1];
				n1++;
				continue;
			}
			if(nums1[n1] >= nums2[n2]) {
				nums1[i] = nums2[n2];
				n2++;
			}else {
				nums1[i] = nums1[n1];
				n1++;
			}
		}
	
        
    }
}
```