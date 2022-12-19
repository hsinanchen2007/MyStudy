### 解法一：递归
计算二叉树的所有左叶子之和，就是计算二叉树的**左子树的所有左叶子之和**，加上二叉树的**右子树的所有左叶子之和**。
当遇到一棵树，它的左节点恰好是叶子时，则这棵树的所有左叶子之和，就是这个左叶子结点，加上这棵树的右子树的所有左叶子之和。
以上就是递归的主要内容。
递归边界就是遇到空树时，返回0，空树所有左叶子之和显然为0。

代码：
```java
class Solution {
    public int sumOfLeftLeaves(TreeNode root) {
        if(root == null)    
            return 0;
        if(root.left != null && root.left.left == null && root.left.right == null)
            return root.left.val + sumOfLeftLeaves(root.right);
        return sumOfLeftLeaves(root.left) + sumOfLeftLeaves(root.right);
    }
}
```

### 解法二：迭代
相当于层序遍历，借助队列，逐个结点判断：
从队列中取出结点，如果左子节点为叶子结点，将其累加到结果；
如果左子节点不是叶子结点而是普通结点，将其入列；
然后把右子节点入列（不为空才入列）。
这样就完成了一次循环。

代码：
```java
class Solution {
    public int sumOfLeftLeaves(TreeNode root) {
        if(root == null)    return 0;
        int sum = 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty())
        {
            TreeNode cur = q.poll();
            if(cur.right != null)
                q.offer(cur.right);
            if(cur.left != null && cur.left.left == null && cur.left.right == null)
                sum += cur.left.val;
            else if(cur.left != null)
                q.offer(cur.left);
        }
        return sum;
    }
}
```

### 复杂度
时间复杂度：$O(n)$。
空间复杂度：最坏情况$O(n)$。