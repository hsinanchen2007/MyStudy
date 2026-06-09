### 解题思路
解题思路：
使用二分查找从数组中找到第一个大于target的索引。
然后从该索引位置向前遍历，直到第一个小于target的索引，统计其中值为target的元素。

复杂度分析：
- 时间复杂度：二分查找的复杂度为O(logN)， 线性遍历的复杂度为O(K)
- 空间复杂度：O(1)

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if (nums.length == 0) {
            return 0;
        }
        int start = 0;
        int end = nums.length - 1;
        //找到第一个大于target的索引
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target) {
                end = mid;
            } else if (nums[mid] < target) {
                start = mid;
            } else {
                start = mid;
            }
        }
        int first = end;
        if (nums[end] > target) {
            first = end;
        }
        if (nums[start] > target) {
            first = start;
        }
        int count = 0;
        while (first >= 0) {
            if (nums[first] > target) {
                first--;
            } else if (nums[first] == target) {
                count++;
                first--;
            } else {
                break;
            }
        }
        return count;
    }
}
```