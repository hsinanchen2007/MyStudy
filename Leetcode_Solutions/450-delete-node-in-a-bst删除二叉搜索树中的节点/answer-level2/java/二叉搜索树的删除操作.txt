### 解题思路
此处撰写解题思路
1.先找到要删除的节点和它的父节点
2.判断该节点的子节点个数
    2.1 如果有两个子节点，则找到右子树的左叶子节点，将值放入到该节点，把问题转化成删除右子树的左叶子节点
    2.2 如果有一个子节点，则将其父节点指向下一个节点
    2.3 如果其是叶子节点，则将其父节点指向空
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
        if(root==null){
            return root;
        }

        TreeNode p=root;
        TreeNode pp=null; //key节点的父节点
        while (p!=null&&p.val!=key){
            pp=p;
            if (p.val<key){
                p=p.right;
            }else {
                p=p.left;
            }
        }

        if (p==null){
            return root;
        }


        if (p.left!=null&&p.right!=null){//key节点有两个子节点
            TreeNode minp=p.right;
            TreeNode minpp=p;//pp是p的父节点

            while (minp.left!=null){
                minpp=minp;
                minp=minp.left;
            }
            p.val=minp.val;
            pp=minpp;//把删除key节点转成删除右子树的左叶子节点，把删除操作放在了删除叶子节点的操作
            p=minp;
        }


        TreeNode chird;//key节点只有一个子节点或者自身就是叶子节点
        if (p.left!=null){
            chird=p.left;//只有左子节点
        }else if (p.right!=null){
            chird=p.right;//只有右子节点
        }else {
            chird=null;//自身是叶子节点
        }

        if (pp==null){//根节点
            root=chird;
        }else if (pp.left==p){
            pp.left=chird;
        }else if (pp.right==p){
            pp.right=chird;
        }
        return root;
    }
}
```