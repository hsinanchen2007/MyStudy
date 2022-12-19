### 解题思路
关键是这个高度平衡二叉树是怎么一回事，根节点是数组的中间值（这里选择中间或者中间两个的偏右一个），左子节点又是数组左边部分的中间值，右子节点是数组右边部分的中间值。

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
        if(nums.length == 0){
            return null;
        }
        TreeNode treeNode = getSubTreeNode(nums);
        int[] left = Arrays.copyOf(nums,(nums.length)/2);
        int[] right = Arrays.copyOfRange(nums,(nums.length)/2+1,nums.length);
        treeNode.left = sortedArrayToBST(left);
        treeNode.right = sortedArrayToBST(right);
        return treeNode;
    }

    public TreeNode getSubTreeNode(int[] nums) {
        return new TreeNode(nums[(nums.length)/2]);
    }
}
```