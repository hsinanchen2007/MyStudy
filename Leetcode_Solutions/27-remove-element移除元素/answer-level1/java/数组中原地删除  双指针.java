### 解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :38.1 MB, 在所有 Java 提交中击败了5.15%的用户
数组中删除的问题，只需要原地删除，返回之后的长度。
于是按照搬位置的方法，只要不符合val的就依次搬到0 1 2 号位置，判断完就完了。
count = -1,主要是考虑到没有插入之前，下标在0号下标之前，插入后，才有下标。
所以假如依次都没插入，就长度= 下标 + 1，就是0长度。

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int count = -1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != val) {
                count++;
                nums[count] = nums[i];
            }
        }
        return count + 1;
    }
}
```