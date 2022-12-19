### 解法一：递归
判断一棵树是否为对称二叉树，即判断它的左右两个子树是否镜像对称。
左右两子树镜像对称意味着这两棵树其中之一的左右子树做镜像变换后，将和另一棵树相同。例如，以root.right为根结点的树做左右子树镜像变换后，将和以root.left为根结点的树相同。则问题回到了判断相同的树上。可参考问题100.相同的树。

如何将一棵树做镜像变换？其实只需在遍历的时候将左右子树的顺序颠倒即可。
因此，对于原根结点root，只需对左子树按先序遍历，对右子树按颠倒过的先序遍历，来判断树是否相同即可。

时间复杂度：O(n)。
空间复杂度：O(n)。

代码：
```java
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root == null)    return true;
        return isSameTree(root.left, root.right);
    }
    private boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null)
            return true;
        if((p == null) != (q == null))
            return false;
        if(p.val != q.val)
            return false;
        return isSameTree(p.left, q.right) && isSameTree(p.right, q.left);
    }
}
```

### 解法二：迭代
用层序遍历来判断，即迭代法。
初始时，向队列中添加两次root，此后每次循环都从队列取出两个结点，做判断：
如果两个结点均为空，则跳过本次循环，继续取两个结点出来判断；
如果一空一非空，则不符合镜像条件；
如果均不空且值不同，也不符合镜像条件；
如果均不空且值相同，则符合镜像条件；
这两个结点共有4个子结点，接下来应该把它们加入队列。
上述方法是如何做到判断对称二叉树的，下面将从顶点入队方式的角度来解释：
入队的方式与普通的层序遍历不同，因为要满足每次从队列取出的两个结点在树中的位置为镜像的条件，才能用这两个顶点来判断对称二叉树。因此，对子结点的入队顺序也有要求，每加入一个结点后，下一个加入的必须是位置上与上一个入队的顶点镜像的顶点。

时间复杂度：O(n)。
空间复杂度：O(n)。

代码：
```java
class Solution {
    public boolean isSymmetric(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        q.offer(root);
        while(!q.isEmpty())
        {
            TreeNode l = q.poll();
            TreeNode r = q.poll();
            if(l == null && r == null)
                continue;
            if(l == null || r == null)
                return false;
            if(l.val != r.val)
                return false;
            q.offer(l.left);
            q.offer(r.right);
            q.offer(l.right);
            q.offer(r.left);
        }
        return true;
    }
}
```