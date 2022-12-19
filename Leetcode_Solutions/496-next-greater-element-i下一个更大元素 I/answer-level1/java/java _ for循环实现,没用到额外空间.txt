思路很简单，代码实现也很简单的一种方法，但是效率不知为何很差，也没用到额外的空间
nums2从后往前找，大于要查找的值时替换temp直到查找到该值时，将temp赋值给nums1
```
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        for (int i = 0; i < nums1.length; i++) {
            int temp = -1;
            for (int j = nums2.length - 1; j >= 0; j--) {
                if (nums1[i] < nums2[j]) {
                    temp = nums2[j];
                }
                if (nums1[i] == nums2[j]) {
                    nums1[i] = temp;
                    break;
                }
            }
        }
        return nums1;
    }
}
```
