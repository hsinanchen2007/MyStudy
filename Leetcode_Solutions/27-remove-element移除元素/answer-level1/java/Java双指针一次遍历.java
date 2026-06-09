### 解题思路
指针k记录有多少个不等于val的数的个数，对数组进行遍历，将不等于val的数赋值给指针k所在的元素同时将k向后移动一位。
遍历完成后，k值就表示删除val后新数组的长度。

与

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int k = 0;
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
}
```