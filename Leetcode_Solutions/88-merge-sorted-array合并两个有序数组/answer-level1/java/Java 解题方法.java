### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if (m == 0) {
            for (int x = 0; x < n; x++) {
                nums1[x] = nums2[x];
            }
        }
        int len = m + n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == m -1 && nums2[i] > nums1[j]) {
                    nums1[m] = nums2[i];
                    m++;
                    break;
                }else if (nums2[i] <= nums1[j]) {
                    for (int k = m -1 ; k >= j; k--) {
                        nums1[k+1] = nums1[k];
                    }
                    nums1[j] = nums2[i];
                    m++;
                    break;
                }
            }
        }
    }
}
```