### 解题思路
从后往前遍历，比较nums1[i]和nums2[j]大小
- nums2[j]大，注意nums1为空的情况，即i==-1，此时将nums2依次装入nums1即可
```
	if(i == -1 || nums1[i] < nums2[j]) {
		nums1[l] = nums2[j];
		j--;
	}
```
- nums1[i]大
```
	nums1[l] = nums1[i];
	i--;
```
- 当j == -1的时候跳出，完成排序

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int l = nums1.length - 1;
		for(int i = m - 1, j = n - 1; j >= 0;) {
			if(i == -1 || nums1[i] < nums2[j]) {
				nums1[l] = nums2[j];
				j--;
			}else {
				nums1[l] = nums1[i];
				i--;
			}
			l--;
			if(j == -1)
				break;
		}
    }
}
```