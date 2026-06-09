首先看一下104题  求二叉树的最大深度

```reasonml
class Solution {
    public int maxDepth(TreeNode root) {
        
        if (root == null)
            return 0;
        
        int leftDepth = maxDepth(root.left);
        int rightDepth = maxDepth(root.right);
        
        return Math.max(leftDepth, rightDepth) + 1;
    }
}
```

本题目与104题的区别在于递归条件
求最大深度递归到底时必然是叶子节点
但是求最小深度如果单单把Math.max改成Math.min, 返回的最小值并非是到达的叶子节点的最小值,  画个图就明白了

```yaml
         3
     /      \
   9        20
  / \      / 
2    4    5
```


上面这棵树如果使用求最大深度的方法求得的结果就是 3->20的深度 为2
但是20这个节点并非是一个叶子节点, 所以这样求得的结果是不对的
递归结束的条件必须还得判断左右子树是否为空的情况   代码如下:


```reasonml
class Solution {
    public int minDepth(TreeNode root) {
        
        if (root == null)
            return 0;
        
        if (root.left == null && root.right != null)
            return minDepth(root.right) + 1;
        
        if (root.right == null && root.left != null)
            return minDepth(root.left) + 1;
        
        
        return Math.min(minDepth(root.left), minDepth(root.right)) + 1;

    }
}
```

