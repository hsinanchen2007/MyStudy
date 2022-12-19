思路是不断地去找p和q的位置，到底在哪个子树中，找的过程中，可能会返回null,p,q,普通Node。
（1）返回p,q就说明pq在当前节点的子树中（或当前节点就是）
（2）返回普通Node说明找到了pq的最近公共祖先。
（3）返回null说明pq不在该节点的子树。

寻找的过程中，首先是判断当前root,如果满足root为null或为p或为q直接返回,之后会递归判断root的left,进行剪枝判断是否需要递归root.right,如果需要则会递归判断root的right.

其实思路都大同小异，剪枝的套路也相同，我想说点别的题解没说的：

1.下面的代码其实还有一层含义是，如果root为p或q就可以直接返回，不需要判断root的左右子树，因为即使另一个结点在root的左子树,**root也是他们的最近公共节点**。
```
 if (root==null||root==p||root == q)
            return root;
```
对应这种特殊情况（p和q中一个是另一个父节点）,最终递归返回到到根节点时,left和right一个为null,一个不为null,最终就会返回不为null的节点(也就是公共祖先)。

2.对应left,我们唯一能做的剪枝只有如果left是一个普通Node的话，我们可以直接返回Node,因为找到了最近公共节点。
我猜想肯定有人在想，**如果left为p或者为q，那么是不是就可以直接返回root？**，因为右子树肯定是另一个节点，不需要判断right了，进行剪枝。
这个是**错误**的，因为另一个节点还可能在其他的子树中，我们判断的root可能只是其中一个小子树。
```
  TreeNode left = lowestCommonAncestor(root.left, p, q);
        //这里如果left直接返回另一个普通TreeNode就是找到了最近公共祖先
        if (left!=null&&left!=q&&left!=p)
            return left;
```

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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        /*
        该函数是要找p和q的位置，因此返回值可能是null，p，q，普通TreeNode

        */
        //如果root为null或者为p或q，都直接返回root，其实root为p和q返回root的含义第一层是要返回root来通知root的父节点
        //还有一层是如果另一个节点在root的子树中也不需要判断了,它们的最近公共祖先肯定就在root。
        if (root==null||root==p||root == q)
            return root;
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        //这里如果left直接返回另一个普通TreeNode就是找到了最近公共祖先
        if (left!=null&&left!=q&&left!=p)
            return left;
        //这里要注意不可以剪枝，因为即使left为p或者q，也不能直接返回root，因为另一个节点不一定在right中，
        //所以要继续递归right,根据right的值决定返回值。
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        //与left那个同理
        if(right!=null&&right!=q&&right!=p)
            return right;
            
        //一个为p一个为q，肯定要返回root，因为root就是最近公共节点
        if(left!=null&&right!=null)
            return root;
        
        return left==null?right:left;
    }
}
```
