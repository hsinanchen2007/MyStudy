### 解题思路
二叉搜索树：根节点值大于左子节点值，小于右子节点值。
当前节点值小于目标值时，向右搜索（当前节点值是扫描过的小于目标值的节点值中的最大的一个）；当前节点值大于目标值时，向左搜索（当前节点值是扫描过的大于目标值的节点值中的最小的一个）。

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
    public int closestValue(TreeNode root, double target) {
        int first = root.val;
        int second = root.val;
        TreeNode head = root;
        while(head!=null){
            if(head.val == target){
                return head.val;
            } else if(head.val<target){
                first = head.val;
                head = head.right;
            } else if(head.val>target){
                second = head.val;
                head = head.left;
            }
        }
        return Math.abs(first-target)<Math.abs(second-target)?first:second;
    }
}
```