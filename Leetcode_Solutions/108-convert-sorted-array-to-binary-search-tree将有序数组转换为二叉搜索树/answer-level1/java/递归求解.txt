### 解题思路
insert 负责插入start和end的中间点
递归insert就好了
### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
  public TreeNode sortedArrayToBST(int[] nums) {
        return insert(nums, 0, nums.length - 1);
    }

    public TreeNode insert(int[] nums, int start, int end) {
        if (start > end) {
            return null;
        }
        int mid = (start + end) / 2;
        TreeNode t = new TreeNode(nums[mid]);
        if (mid > start) {
            t.left = insert(nums, start, mid - 1);
        }
        if (mid < end) {
            t.right = insert(nums, mid + 1, end);
        }

        return t;
    }
}
```