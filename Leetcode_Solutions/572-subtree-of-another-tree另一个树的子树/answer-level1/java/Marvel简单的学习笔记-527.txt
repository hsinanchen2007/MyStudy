### 比较每棵子树
给定两棵非空二叉树，判断其中一棵树t是否为另一棵树s的子树（相同结构相同结点值）。
还要注意到，这不是二叉搜索树BST，而且树中各个结点的值可能重复。

思路：
可以把s树中的每一个结点（包括根结点）视为以这个结点为根的子树，然后把s中的每一棵子树都与t作比较，判断是否相同即可。
判断是否相同的函数可参考题目100.相同的树。

### 递归比较：
代码简洁，即判断根结点这棵子树与树t是否相同，即isSame(s, t)方法；
再递归判断左子树中是否含有子树与t相同，即isSubtree(s.left, t)方法；
再递归判断右子树中是否含有子树与t相同，即isSubtree(s.right, t)方法。
```java
class Solution {
    public boolean isSubtree(TreeNode s, TreeNode t) {
        if(s == null)   return false;
        return isSame(s, t) || isSubtree(s.left, t) || isSubtree(s.right, t);
    }
    private boolean isSame(TreeNode s, TreeNode t) {
        if(s == null && t == null)  
            return true;
        if(s == null || t == null)
            return false;
        if(s.val != t.val)
            return false;
        return isSame(s.left, t.left) && isSame(s.right, t.right);
    }
}
```

### 迭代找到根结点与t的根结点相同的子树，再开始比较：
```java
class Solution {
    public boolean isSubtree(TreeNode s, TreeNode t) {
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(s);
        while(!q.isEmpty())
        {
            TreeNode cur = q.poll();
            if(cur.val == t.val && isSame(cur, t))
                return true;
            if(cur.left != null)    q.offer(cur.left);
            if(cur.right != null)   q.offer(cur.right);
        }
        return false;
    }
    private boolean isSame(TreeNode s, TreeNode t) {
        if(s == null && t == null)  
            return true;
        if(s == null || t == null)
            return false;
        if(s.val != t.val)
            return false;
        return isSame(s.left, t.left) && isSame(s.right, t.right);
    }
}
```