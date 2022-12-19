我首先的思路就是要有一个reach函数，可以判断一个节点是不是指定节点的祖先，通过dfs实现，返回一个bool值。
那么这道题要寻找离p、q最近的祖先节点，就可以再使用一个dfs，我们都知道dfs回溯的时候是从下往上的，那么只要调用函数最早对参数p、q都返回true的节点就是要得到的答案了，然后沿着回溯返回值链传回这个节点。

代码：

```java
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null) return null;
        TreeNode left = lowestCommonAncestor(root.left,p,q);
        if(left!=null) return left;
        TreeNode right = lowestCommonAncestor(root.right,p,q);
        if(right!=null) return right;
        if(reach(root,p.val)==true&&reach(root,q.val)==true) return root;
        return null;
    }
    public boolean reach(TreeNode root,int value){
        if(root == null) return false;
        if(root.val == value) return true;
        return reach(root.left,value) || reach(root.right,value);
    }
}
```