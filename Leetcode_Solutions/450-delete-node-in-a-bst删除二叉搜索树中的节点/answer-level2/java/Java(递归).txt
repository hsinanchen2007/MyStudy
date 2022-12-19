### 解题思路
详见备注

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
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root==null) return null;
        if(key>root.val) root.right=deleteNode(root.right,key);
        else if(key<root.val) root.left=deleteNode(root.left,key);
        else{
            // 左子树为空 返回右子树
            if(root.left==null) return root.right;
            else{
                // 右子树为空 或 左右子树都不为空 使用前驱结点的值替换后 返回
                // 默认没有空构造器 随便输个0
                TreeNode res=new TreeNode(0);
                res.left=getPreNode(root.left,res);
                res.right=root.right;
                return res;
            }
        }
        return root;
    }

    /**
    * 左子树找前驱结点
    * 并把前驱结点的左子树作为其父结点的右子树
    */
    public TreeNode getPreNode(TreeNode root,TreeNode res){
        if(root.right==null){
            // 把值换成对应的前驱结点的值
            res.val=root.val;
            return root.left;
        }
        root.right=getPreNode(root.right,res);
        return root;
    }

}
```