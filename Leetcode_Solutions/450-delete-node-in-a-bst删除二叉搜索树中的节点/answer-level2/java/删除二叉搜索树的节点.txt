本题是一个二叉搜索树中的经典问题。
1.如何找到二叉搜索树的前驱节点还有后继节点。
2.如何理解递归思想？
3.分类讨论

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
    //1.在二叉搜索树中找到该点的后继节点
        public int successor(TreeNode root)
        {
            root=root.right;
            while(root.left!=null)
                root=root.left;
            return root.val;
        }

        public int precessor(TreeNode root)
        {
            root=root.left;
            while(root.right!=null)
                root=root.right;
            return root.val;
        }

    public TreeNode deleteNode(TreeNode root, int key) {
        if(root==null)
            return null;
        if(key>root.val)  //这个点就在该树的右子树，递归删除右子树中的点
        {
            root.right=deleteNode(root.right,key);
        }
        else if(key<root.val)
        {
            root.left=deleteNode(root.left,key);
        }
        //否则就是删除该节点
        else{
            if(root.right==null&&root.left==null)  //如果该树的左右子树都是空的
                root=null;  //直接删除这个叶子结点
            else if(root.right!=null)  //如果它的右子树不空，那么能找到它的后继节点
            {
                root.val=successor(root);
                root.right=deleteNode(root.right,root.val);
            }
            else if(root.left!=null)
            {
                root.val=precessor(root);
                root.left=deleteNode(root.left,root.val);
            }
        }
        return root;
    }
}
```