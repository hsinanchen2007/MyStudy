### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // 从后往前填值，每次找最大
        int index = m + n - 1;
        if (index < 0) return;

        int max1 = m - 1;
        int max2 = n - 1;
        while (max1 >= 0 && max2 >= 0) {
            // 两个数组都还有元素未处理的情况，就循环
            nums1[index --] = nums1[max1] > nums2[max2] ? nums1[max1 --] : nums2[max2 --];
        }
        // 结束循环后，如果num2空，不用处理，如果num1空num2不空，拷到num1
        while (max2 >= 0) {
            nums1[index --] = nums2[max2 --];
        }
    }
}
```