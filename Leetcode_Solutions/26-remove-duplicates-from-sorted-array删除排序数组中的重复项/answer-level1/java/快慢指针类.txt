### 解题思路
主要是用到了两个下标，下标位置的确定是关键吧。
想法：有一个下标一直在记录正确的位置，有一会数据一直在记录上一次的元素。
有一个下标跑完全程，只有当遇到的元素不是上一次记录的元素，说明要插入，上一个元素已经结束，要开始判断下一个元素。
执行用时 :1 ms, 在所有 Java 提交中击败了99.73%的用户
内存消耗 :41.1 MB, 在所有 Java 提交中击败了16.96%的用户
### 代码

```java
class Solution {
    //额外空间O(1):指空间大小不随外部变化，指常数
    public int removeDuplicates(int[] nums) {
        int start = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[start] != nums[i]) {
                start = start + 1;
                nums[start] = nums[i];
            }
        }
        return start + 1;
    }
}
```