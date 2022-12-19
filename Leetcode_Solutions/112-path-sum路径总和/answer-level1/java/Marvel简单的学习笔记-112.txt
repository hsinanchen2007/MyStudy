### 对新手友好的树遍历入门
树的搜索或遍历，一般来说无非就是递归，dfs，bfs，其实关于树，这些都是非常好理解的算法，接下来就是怎么把它们写出来。
对着答案在纸上或脑海中多比划多模拟，树的题目对锻炼递归很有帮助。

### 解法一：啰嗦但好懂的递归/dfs
关于求路径的题，很容易联想到递归/dfs，因为这很自然，从根节点出发，沿着一个方向不断深入每个结点，直至尽头完成一条路径后，才回头搜索下一条路径。
本题也是，利用深度优先搜索（递归），沿着一个方向一个一个结点检查，如果到达根结点并且满足总和sum的要求，结果设为true后直接返回；否则，检查左子节点，再检查右子节点，然后返回前要把自身的val加回去，因为要回头搜索下一条路了。

代码：
```java
class Solution {
    private boolean res;
    public boolean hasPathSum(TreeNode root, int sum) {
        dfs(root, sum);
        return res;
    }   
    private void dfs(TreeNode root, int cur) {
        if(root == null)    return;
        if(res)             return;
        cur -= root.val;
        if(root.left == null && root.right == null)
        {
            if(cur == 0)    res = true;
            cur += root.val;
            return;
        }
        dfs(root.left, cur);
        dfs(root.right, cur);
        cur += root.val;
    }
}
```

### 解法二：更简洁的递归
经过练习后你会发现，这种写法原来更容易。
对于根结点root是否有一条满足sum要求的路径，这个问题的答案等价于：
对于根结点的左右子结点来说是否有一条满足$(sum-root.val)$要求的路径。以此类推。
所以很容易写出代码`return hasPathSum(root.left, sum) || hasPathSum(root.right, sum);`
但是别忘了递归边界，还有更新sum、判断叶子结点等的处理步骤。

代码：
```java
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root == null)    
            return false;
        sum -= root.val;
        if(root.left == null && root.right == null)
            return sum == 0;
        return hasPathSum(root.left, sum) || hasPathSum(root.right, sum);
    }
}
```

### 解法三：相当于层序遍历的bfs
这个应该不难，但关于路径的问题用dfs/递归或许更合适，bfs/层序遍历则需要多一些辅助。
层序遍历有一个最大的特点：从队列出列一个结点后，我们不知道它的前趋顶点，即不知道它的父节点是谁，这导致我们无法统计它所在路径当前的sum。
解决办法可以新建一个队列作辅助，这个队列存储的是从起点到某结点的路径的sum总和。
每当入列一个结点，同时入列一个sum值（从起点到该顶点路径的sum），出列亦如是。
这样可以不需要知道结点的父节点，因为我们已经有了当前的sum，入列新结点时，新的sum值就是当前sum加上新节点的val。

```java
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root == null)    return false;
        boolean res = false;
        Queue<TreeNode> q1 = new LinkedList<>();
        Queue<Integer> q2 = new LinkedList<>();
        q1.offer(root);
        q2.offer(root.val);
        while(!q1.isEmpty())
        {
            TreeNode cur = q1.poll();
            int temp = q2.poll();
            if(cur.left == null && cur.right == null && temp == sum)
                res = true;
            if(cur.left != null)
            {
                q1.offer(cur.left);
                q2.offer(cur.left.val + temp);
            }
            if(cur.right != null)
            {
                q1.offer(cur.right);
                q2.offer(cur.right.val + temp);
            }
        }
        return res;
    }
}
```

### 复杂度
时间复杂度：最坏情况$O(n)$。
空间复杂度：最坏情况$O(n)$。