
```scala
object Solution {
    def getMinimumDifference(root: TreeNode): Int = {
        var min=Int.MaxValue;
        var pre:TreeNode=null
        def inOrder(root:TreeNode):Unit={
            if (Option(root).nonEmpty){
                inOrder(root.left);
                if (pre!=null)
                    min=Math.min(min,Math.abs(pre.value-root.value));
                pre=root;
                inOrder(root.right)
            }
        }
        inOrder(root);
        min

    }
}
```
