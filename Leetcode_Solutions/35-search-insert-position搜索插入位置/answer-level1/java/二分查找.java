执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :38.6 MB, 在所有 Java 提交中击败了76.79%的用户
### 解题思路
此处撰写解题思路
二分查找，使用left、right、mid，正好命中则返回当前索引，不然最终返回left
### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
          int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            if (nums[(left + right) / 2] == target) {
                return (left + right) / 2;
            }
            if (nums[(left + right) / 2] > target) {
                right = (left + right) / 2 - 1;
            }
            if (nums[(left + right) / 2] < target) {
                left = (left + right) / 2 + 1;
            }
        }
        return left;
    }
}
```