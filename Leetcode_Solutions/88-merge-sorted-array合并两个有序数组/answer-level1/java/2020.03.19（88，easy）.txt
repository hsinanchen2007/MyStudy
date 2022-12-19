### 解题思路
本题使用**双索引尾指针**，从每个数组的最后一个元素开始比较

通过while循环，依次对两个数组的**最尾元素**进行比较，将大的元素放入合并后的nums1的**最尾处**

最后通过System.arraycopy(nums2, 0, nums1, 0, l2 + 1);将nums2数组剩下的元素放到nums1的最前面去即可完成合并。

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int l1 = m - 1;
        int l2 = n - 1;
        int len = m + n - 1;       
        while(l1 >= 0 && l2 >= 0){
            nums1[len--] = nums1[l1] > nums2[l2] ? nums1[l1--] : nums2[l2--];
        }
        // 将nums2数组从下标0开始,拷贝到nums1数组中,从下标0位置开始,长度为l2+1
        System.arraycopy(nums2, 0, nums1, 0, l2 + 1);
    }
}
```