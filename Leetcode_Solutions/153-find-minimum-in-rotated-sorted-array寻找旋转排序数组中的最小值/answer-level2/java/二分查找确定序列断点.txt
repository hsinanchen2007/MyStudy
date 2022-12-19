### 解题思路
要在头脑中想出数组旋转后，是怎样的一个图。由于有序性，可以想到二分查找，但是针对中间节点的大小，要进行判断往哪边搜索

### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        int len = nums.length;
        //如果没有旋转，则完全升序排列，第0个小于最后一个
        if (nums[0] < nums[len - 1]) {
            return nums[0];
        }
        //其他都是旋转过的，必定是两段升序序列，且第一段序列全部都大于第二段序列
        int left = 0, right = len - 1;
        while (left < right - 1) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) {
                //中间位置的数字较大，说明在第一段升序序列中，则往右边搜索
                left = mid;
            } else {
                //中间位置较小，说明在第二段升序序列中，往左搜索
                right = mid;
            }
        }

        //退出循环时，正好是断点，左边是第一段升序序列的末尾，右边是第二段升序序列的开始，也就是最小值
        return nums[right];
    }
}
```