## 三种解法加深理解树的遍历

### 解法一：DFS
每访问树的一个结点，只要符合区间要求，记下该结点值；若不符合，结点值记为0。
二叉树的范围和，等于当前结点值，加上左子树的范围和，再加上右子树的范围和。
这样的递归就是深度优先搜索。

代码：
```java
class Solution {
    public int rangeSumBST(TreeNode root, int L, int R) {
        if(root == null)    return 0;
        int cur = 0;
        if(root.val >= L && root.val <= R)
            cur = root.val;
        return cur + rangeSumBST(root.left, L, R) + rangeSumBST(root.right, L, R);
    }
}
```

### 解法二：BFS
相当于层序遍历树的每个结点，只要符合区间要求，就累加结点值。
遍历完成后返回累加的结果即可。

代码：
```java
class Solution {
    public int rangeSumBST(TreeNode root, int L, int R) {
        if(root == null)    return 0;
        int sum = 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty())
        {
            TreeNode cur = q.poll();
            if(cur.val >= L && cur.val <= R)
                sum += cur.val;
            if(cur.left != null)    q.offer(cur.left);
            if(cur.right != null)   q.offer(cur.right);
        }
        return sum;
    }
}
```

### 解法三：利用BST的特性改进解法一
题目给定的是BST，而解法一中的dfs并没有利用到这个条件。
由于BST的左右子节点和父节点有大小关系的限制，因此可以根据父节点的值来判断是否有必要递归遍历左右子树。
如果当前结点值小于L，那么左子树的所有结点只会更小，更不会处于[L,R]区间内，因此无需再考虑左子树，直接返回右子树的范围和即可；
如果当前结点值大于R，那么右子树的所有结点只会更大，更不会处于[L,R]区间内，因此无需再考虑右子树，直接返回左子树的范围和即可；
若当前结点处于[L,R]区间内，则返回当前结点值加上左子树的范围和再加上右子树的范围和。
这样就不用再像解法一那样遍历许多无效路径。

代码：
```java
class Solution {
    public int rangeSumBST(TreeNode root, int L, int R) {
        if(root == null)    return 0;
        if(root.val < L)
            return rangeSumBST(root.right, L, R);
        if(root.val > R)
            return rangeSumBST(root.left, L, R);
        return root.val + rangeSumBST(root.left, L, R) + rangeSumBST(root.right, L, R);
    }
}
```

改进后的迭代版本：
```java
class Solution {
    public int rangeSumBST(TreeNode root, int L, int R) {
        if(root == null)    return 0;
        int sum = 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty())
        {
            TreeNode cur = q.poll();
            if(cur.val >= L && cur.val <= R)
                sum += cur.val;
            if(cur.val > L && cur.left != null)
                q.offer(cur.left);
            if(cur.val < R && cur.right != null)
                q.offer(cur.right);
        }
        return sum;
    }
}
```