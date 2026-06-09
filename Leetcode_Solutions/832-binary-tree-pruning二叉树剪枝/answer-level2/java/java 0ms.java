### 解题思路
深度遍历

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
    public TreeNode pruneTree(TreeNode root) {
        root = prune(root);
        return root;
    }

    TreeNode prune(TreeNode r){
        if(r==null) return null; //递归出口
        
        //分别处理左右子树
        if(r.left!=null){
            r.left = prune(r.left);
        }
        if(r.right!=null){
            r.right = prune(r.right);
        }

        //递归出口
        //如果左右子树为空且本节点为0，则设本节点为空
        if( r.left==null && r.right==null && r.val==0 ){
            return null;
        }
        //返回本节点
        return r;
    }
}
```