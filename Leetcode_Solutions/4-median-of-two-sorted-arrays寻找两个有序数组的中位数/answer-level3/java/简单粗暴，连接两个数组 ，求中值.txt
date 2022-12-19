### 解题思路

![2020-03-05_093633.jpg](https://pic.leetcode-cn.com/f71ec048a0f9e73452b67ae0723b6fa705a66696856586d35031129b688d8d7c-2020-03-05_093633.jpg)


利用系统方法连接两个数组，进行排序。
求出中值。

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] result = Arrays.copyOf(nums1, nums1.length + nums2.length);
        System.arraycopy(nums2, 0, result, nums1.length, nums2.length);
        Arrays.sort(result);
        return result.length % 2 == 1 ? result[result.length / 2] : 
        (result[result.length / 2 - 1] + result[result.length / 2]) / 2.0;
    }
}
```