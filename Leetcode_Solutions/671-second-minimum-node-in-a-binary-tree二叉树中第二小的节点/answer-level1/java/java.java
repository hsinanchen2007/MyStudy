### 解题思路
1 首先判断根节点的值与左右子节点值的关系。
2 如果左节点的值等于根节点的值而右节点的值不等于根节点的值，那么第二小的值必然在左子树上（也即递归中的l!=-1,返回l），递归遍历左子树即可。
3 如果右节点的值等于根节点的值而左子节点的值不等于根节点的值，那么第二小的值必然在右子树（也即递归中的r！=-1），递归遍历右子树即可。
4 如果左节点的值和右节点的值同时等于或者同时不等于根节点的值，则同时遍历左右子树。（也即返回l和r中的最小值）

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
    public int findSecondMinimumValue(TreeNode root) {
        if(root==null||(root.left==null&&root.right==null)) return -1;
        int l=root.left.val;
        int r=root.right.val;
        if(root.val==l) l=findSecondMinimumValue(root.left);
        if(root.val==r) r=findSecondMinimumValue(root.right);
        if(l!=-1&&r!=-1){
            return Math.min(l,r);
        }
        if(l!=-1) {return l;
        }else{
            return r;
        }
    }
}
```