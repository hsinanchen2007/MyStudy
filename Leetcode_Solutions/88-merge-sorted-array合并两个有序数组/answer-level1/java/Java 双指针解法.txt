### 解题思路
从后往前同时遍历两数组，从nums1中两数组元素数量和的位置开始填入遍历时较大的元素；
若nums1先遍历完毕，则代表nums2中还剩余一些小数字，直接放入nums1的开头位置。

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int pos1 = m - 1;
        int pos2 = n - 1;
        int curPos = m + n - 1;
        while (pos1 >= 0 && pos2 >= 0) {
            nums1[curPos] = (nums1[pos1] >= nums2[pos2]) ? nums1[pos1--] : nums2[pos2--];
            curPos--;
        }
        // 若nums1中的元素先合并完毕，则将nums2中的剩余元素放到nums1前
        if (pos2 >= 0) {
            for (int i = 0; i <= pos2; i++) {
                nums1[i] = nums2[i];
            }
        }
    }
}
```