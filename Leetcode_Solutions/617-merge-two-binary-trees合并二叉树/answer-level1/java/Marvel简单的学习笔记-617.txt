### 解法一：递归
不妨以树t1为基础，将t2合并到t1上。

如果两棵树的根结点都不为空，则累加两个根结点的值；
然后合并t1的左子树和t2的左子树；
然后合并t1的右子树和t2的右子树；
最后返回t1作为合并后的子树根结点。
递归边界为：如果t1为空，则返回t2作为子树；如果t2为空，则返回t1作为子树。

代码：
```java
class Solution {
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if(t1 == null)  return t2;
        if(t2 == null)  return t1;
        t1.val += t2.val;
        t1.left = mergeTrees(t1.left, t2.left);
        t1.right = mergeTrees(t1.right, t2.right);
        return t1;
    }
}
```

### 解法二：迭代
相当于层序遍历，对两棵树逐个结点做合并。
同样不妨以t1为基础，将t2合并到t1上。

初始时，只要有一棵树为空，直接返回另一棵树作为合并后的结果。
否则，两棵树均不空，则与层序遍历相同，借助队列，将两棵树的根结点依次入列。
此后，只要队列不空，每次都取出两个结点，一个是t1树上的结点，一个是t2树上的结点，两个结点位置相同。然后开始合并，累加两个结点的值到t1上。接下来，如果两个结点的左子节点都不为空，则将两个结点的左子结点依次入列。如果两个结点的右子节点都不为空，则将两个结点的右子节点依次入列。这样，每次都入列两棵树上同一位置的非空结点，每次都取出两个结点，就可以逐个结点做合并。
但是要注意，上面循环的过程中，只要t1的左子节点为空，就直接将t2的左子结点赋值到t1的左子节点上，无需入队；同理，只要t1的右子节点为空，就直接将t2的右子节点赋值到t1的右子节点上，无需入队。

循环结束，t1就是合并后的树。

```java
class Solution {
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if(t1 == null)  return t2;
        if(t2 == null)  return t1;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(t1);
        q.offer(t2);
        while(!q.isEmpty())
        {
            TreeNode cur1 = q.poll();
            TreeNode cur2 = q.poll();
            cur1.val += cur2.val;
            if(cur1.left != null && cur2.left != null)
            {
                q.offer(cur1.left);
                q.offer(cur2.left);
            }
            else if(cur1.left == null)
                cur1.left = cur2.left;
            if(cur1.right != null && cur2.right != null)
            {
                q.offer(cur1.right);
                q.offer(cur2.right);
            }
            else if(cur1.right == null)
                cur1.right = cur2.right;
        }
        return t1;
    }
}
```