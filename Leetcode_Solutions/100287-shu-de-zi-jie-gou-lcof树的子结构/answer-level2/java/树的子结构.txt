看到二叉树肯定又是递归了，看一个树是不是另一个树的子结构，无非三种情况
1. A，B两个树是不是一样的
2. A.left 和 B 是不是一样的
3. A.right 和 B 是不是一样的

所以问题的关键点就出来了，如何判断两个树是不是一样的？
其实也是三种情况：

1. A.val==B.val
2. A.left=B.left
3. A.right=B.right

知道了这些，剩下的无非就是递归调用的问题了。

```
class Solution {
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if(A==null||B==null) return false;
        return dfs(A,B)||isSubStructure(A.left,B)||isSubStructure(A.right,B);
    }
    public boolean dfs(TreeNode A,TreeNode B){
        if(B==null) return true;
        if(A==null) return false;
        return (A.val==B.val)&&dfs(A.left,B.left)&&dfs(A.right,B.right);
    }
}
```
