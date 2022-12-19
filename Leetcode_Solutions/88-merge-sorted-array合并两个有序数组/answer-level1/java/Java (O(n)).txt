### 解题思路
合并两个有序数组，复制一份新的数组，然后不断检测两个数组的数字哪边更小，把更小的数字插入到新的数组中。

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // O(n)
        int[] nums = new int[m + n];
        int m_index = 0, n_index = 0, i = 0;
        while (m_index < m && n_index < n){
            nums[i++] = (nums1[m_index] <= nums2[n_index]) ? nums1[m_index++] : nums2[n_index++];
        }
        while (m_index < m){
            nums[i++] = nums1[m_index++];
        }
        while (n_index < n){
            nums[i++] = nums2[n_index++];
        }
        for (i = 0; i < m + n; i++){
            nums1[i] = nums[i];
        }
    }
}
```