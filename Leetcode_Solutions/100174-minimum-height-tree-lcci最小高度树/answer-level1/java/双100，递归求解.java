### 解题思路
![屏幕快照 2020-02-20 15.32.20.png](https://pic.leetcode-cn.com/620ec1080f5ee5fc2fa75da545120edb87ea95921b23a854f88441262cd9ac0d-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-20%2015.32.20.png)


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
        return bst(nums, 0, nums.length);
    }

    private TreeNode bst(int[] nums, int start, int end) {
        if (start == end) {
            return null;
        }
        int center = (end + start) >> 1;
        TreeNode node = new TreeNode(nums[center]);
        node.left = bst(nums, start, center);
        node.right = bst(nums, center + 1, end);
        return node;
    }

}
```