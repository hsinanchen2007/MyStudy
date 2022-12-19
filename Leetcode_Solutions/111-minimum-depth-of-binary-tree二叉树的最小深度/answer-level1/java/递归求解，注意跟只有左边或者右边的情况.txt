### 解题思路
- 最小深度，有一种情况当root根节点没有左子树或者右子树的情况，需要只考虑对应有的左子树或右子树计算深度。这种情况考虑右子树深度
```
    3                               
     \         
     20
    /  \
   15   7
```
- 这种情况考虑root的左右子树两边情况。
```
    3
   / \
  9  20
    /  \
   15   7
```
 

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
    public int minDepth(TreeNode root) {
        if(root==null) return 0;
        int left = minDepth(root.left);
        int right = minDepth(root.right);
        //root节点只有左边或者右边情况，left+right+1.
        // 否则，取左边或者右边最小的深度+1
        return  root.left==null || root.right==null  ? left+right+1: Math.min(left,right)+1;
    }
}
```