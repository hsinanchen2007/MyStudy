![1570759275718.jpg](https://pic.leetcode-cn.com/e74ca48f0fe4f8688eca425145d8630770762489d222c5c106354b364b17347d-1570759275718.jpg)



```
public int maxDepth(TreeNode root) {
        if (root == null)
            return 0;
        return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }
```

就三行代码，分析求深度问题，如果考察节点为空，则深度为0，否则，为左子树深度、右子树最大深度+1.
