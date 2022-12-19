## 遍历最常用的两种方法：DFS和BFS

### 解法一：DFS（递归）
二叉树的最大深度，等于左子树的最大深度和右子树的最大深度这两者的较大者，加一。
据此，可用递归求解。

时间复杂度：O(n)。
空间复杂度：O(n)。最坏情况下，树是线性的，则递归需要的栈空间也是线性级别的。

代码：
```java
class Solution {
    public int maxDepth(TreeNode root) {
        if(root == null)    return 0;
        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }
}
```

### 解法二：BFS
借助队列，使用层序遍历的方式。
以层为单元，整层整层地处理，即一轮while循环中处理的结点都是同层的，这样就可以用一个变量记录while循环的次数，最终的次数就是最大层数，即最大深度。
具体操作：从根结点开始，根结点入列后，只要队列不空，每轮处理时，先得到队列中顶点的数目，这表示的是**当前层**顶点的数目。**仅**对这些顶点全部出列然后将它们的子结点全部入列，这样就完成了一次while循环，处理的都是同一层顶点。此时队列中的顶点都是下一层的，下一次while循环处理的自然就是下一层的顶点了。
如此这般，循环次数就是最大深度。

时间复杂度：O(n)。
空间复杂度：O(n)。

代码：
```java
class Solution {
    public int maxDepth(TreeNode root) {
        if(root == null)    return 0;
        int layer = 0;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.offer(root);
        while(!q.isEmpty())
        {
            layer++;
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                TreeNode cur = q.poll();
                if(cur.left != null)    q.offer(cur.left);
                if(cur.right != null)   q.offer(cur.right);
            }
        }
        return layer;
    }
}
```