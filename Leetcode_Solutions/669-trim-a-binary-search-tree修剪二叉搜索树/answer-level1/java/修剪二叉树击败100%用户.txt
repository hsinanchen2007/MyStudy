### 解题思路二叉搜索树的特点：1.左子树中所有节点均小于其根节点2.右子树中所有节点均大于根节点。树
中没有相同的节点。弄清楚返回值是修剪后头结点。


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
    public TreeNode trimBST(TreeNode root, int L, int R) {
        if(root==null) return null;
        else if(root.val>R) return trimBST(root.left,L,R);
        else if(root.val<L) return trimBST(root.right,L,R);
        else if(root.val==L){
            root.left=null;
            root.right=trimBST(root.right,L,R);
        }
        else if(root.val==R){
            root.right=null;
            root.left=trimBST(root.left,L,R);
        }else{
            root.left=trimBST(root.left,L,R);
            root.right=trimBST(root.right,L,R);
        }

        return root;
    }
}
```