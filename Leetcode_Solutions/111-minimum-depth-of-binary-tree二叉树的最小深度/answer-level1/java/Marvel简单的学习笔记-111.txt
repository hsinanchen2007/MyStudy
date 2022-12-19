### 解法一：递归
首先容易想到递归，本质和求树的最大深度一样，不过需要做修改：
一个是注意左子树或右子树为空的情况。
另一个是将求树最大深度时的max改为min。

代码：
```java
class Solution {
    public int minDepth(TreeNode root) {
        if(root == null)        return 0;
        if(root.left == null)   return minDepth(root.right) + 1;
        if(root.right == null)  return minDepth(root.left) + 1;   
        return Math.min(minDepth(root.left), minDepth(root.right)) + 1;
    }
}
```

### 解法二：DFS
深度优先搜索，从树的顶部往下深入，直至叶子结点，根据该叶子结点的深度，更新树的最小深度。
多使用一个形参记录当前结点的深度。

代码：
```java
class Solution {
    private int res;
    public int minDepth(TreeNode root) {
        if(root == null)    return 0;
        res = 0x7fffffff;
        dfs(root, 1);
        return res;
    }
    private void dfs(TreeNode root, int dpth) {
        if(root == null)    return;
        if(root.left == null && root.right == null)
        {
            if(dpth < res)  res = dpth;
            return;
        }
        dfs(root.left, dpth + 1);
        dfs(root.right, dpth + 1);
    }
}
```

### 解法三：BFS
即树的层序遍历，借助队列。
每次只处理同层的结点，即一轮while循环中，同层的结点才出列，并且要全部出列，入列的结点自然都是下一层的。
这样一轮循环代表的是一层结点，期间遇到叶子结点就检查是否可以更新树的最小深度。

代码：
```java
class Solution {
    public int minDepth(TreeNode root) {
        if(root == null)    return 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int layer = 0;
        while(!q.isEmpty())
        {
            layer++;
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                TreeNode cur = q.poll();
                if(cur.left == null && cur.right == null) 
                    return layer;
                if(cur.left != null)    q.offer(cur.left);
                if(cur.right != null)   q.offer(cur.right);   
            }
        }
        return layer;
    }
}
```