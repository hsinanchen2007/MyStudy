## 两种解法：先序与层序

### 解法一：先序
相当于dfs，递归地对两棵树的每个顶点进行比较。

时间复杂度：O(n)。
空间复杂度：O(n)。

代码：
```java
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null)  
            return true;
        if((p == null) != (q == null))
            return false;
        if(p.val != q.val)
            return false;
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
```

### 解法二：层序
相当于bfs，利用队列，层序遍历逐步判断即可。

代码：
```java
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null)
            return true;
        if((p == null) != (q == null))
            return false;
        if(p.val != q.val)
            return false;
        Queue<TreeNode> q1 = new LinkedList<>();
        Queue<TreeNode> q2 = new LinkedList<>();
        q1.offer(p);
        q2.offer(q);
        while(!q1.isEmpty())
        {
            TreeNode n1 = q1.poll();
            TreeNode n2 = q2.poll();
            if(n1.val != n2.val)    return false;
            if((n1.left == null) != (n2.left == null))
                return false;
            if(n1.left != null && n2.left != null)
            {
                q1.offer(n1.left);
                q2.offer(n2.left);
            }
            if((n1.right == null) != (n2.right == null))
                return false;
            if(n1.right != null && n2.right != null)
            {
                q1.offer(n1.right);
                q2.offer(n2.right);
            }
        }
        return true;
    }
}
```