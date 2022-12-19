看了别人写的代码，解释一下
第一种理解：
1.p,q同属于左子树
2.p,q同属于右子树
3.p,q分别属于左子树和右子树
第二种理解：
1.如果p是q的祖先（或者q是p的祖先），返回p没问题，注意对于p的兄弟节点只能返回null，则最终返回p
2.如果互相不是祖先，p在p节点处返回p，q在q节点处返回q，向前逐层返回递归结果的时候，会在首个公共祖先相遇，然后返回公共祖先，注意公共祖先其他的兄弟返回的都是null，最终会返回公共祖先

如果是二叉搜索树更简单，根据二叉搜索树的性质，按照第一种理解可以只去一个子树找就可以。

```java
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null || p==null || q==null)  return null;
        if(root==p || root==q)  return root;
        TreeNode left = lowestCommonAncestor(root.left,p,q);
        TreeNode right = lowestCommonAncestor(root.right,p,q);
        if(left!=null && right!=null)  return root;
        return left!=null?left:right;
    }
}
```
