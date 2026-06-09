递归，将其中一棵树合并到另一棵树即可，不用开辟新的空间，不过这样的坏处是入参就被修改了。如果严格些，要创建新的TreeNode返回。


```java []
class Solution {
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if(t1 == null) return t2;
        if(t2 == null) return t1;
        t1.val += t2.val;
        t1.left = mergeTrees(t1.left, t2.left);
        t1.right = mergeTrees(t1.right, t2.right);
        return t1;
    }
}
```

执行用时 :1 ms, 在所有 Java 提交中击败了99.95%的用户

内存消耗 :48.1 MB, 在所有 Java 提交中击败了65.23%的用户
