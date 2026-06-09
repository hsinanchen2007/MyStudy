### 解题思路
已知排过序 最后是空的* 就从后开始比较两个数组 谁大 就从往后开始放...

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        //while循环 当两个数组 出现一个遍历结束 就跳出循环
        int sum = m + n - 1;//总长度 合并的数组的最后一个index

        //这里while循环结束 还要处理 nums2没有复制完的数字
        while (m != 0 && n != 0) {
            //每次循环 从 两个数组 最后 读两个数字
            nums1[sum] = Math.max(nums1[m - 1], nums2[n - 1]);
            if (nums1[sum] == nums1[m - 1]) m--;
            else n--;
            sum--;
        }

        //处理nums2
        while(n!=0){
            nums1[sum--] = nums2[(n--)-1];
        }
    }
}
```