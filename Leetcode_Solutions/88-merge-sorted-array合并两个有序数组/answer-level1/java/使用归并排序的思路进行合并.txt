### 解题思路
如果理解归并排序，那很快就能解决问题，本题使用的就是归并排序的思路进行合并数组

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
         int[] temp = new int[m + n];
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < m && j < n){
            if(nums1[i] <= nums2[j]){
                temp[k++] = nums1[i++];
            }else if (nums1[i] > nums2[j]){
                temp[k++] = nums2[j++];
            }
        }

        while (i < m){
            temp[k++] = nums1[i++];
        }
        while (j < n){
            temp[k++] = nums2[j++];
        }
        k = 0;
        while (k < m + n){
            nums1[k] = temp[k];
            k++;
        }
    }
}
```