### 解法一：递归
思路很自然，翻转一棵树，从根结点开始，就是颠倒左子节点和右子节点，然后反转左子树，再反转右子树，共三步。
翻转左子树也是三步，先颠倒左子树的左子节点和右子节点，然后反转左子树的左子树，再反转左子树的右子树。
不断递归下去
...
直到递归边界(root == null)，返回null，左子树就算翻转完了。
翻转完左子树应该翻转右子树了，也是三步，先颠倒右子树的左子节点和右子节点，然后翻转右子树的左子树，再翻转右子树的右子树。
左右子树都翻转完了，当前树就算翻转完了，返回当前树的根结点。
递归就这么出来了。

代码：
```java
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if(root == null)    return null;
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        root.left = invertTree(root.left);
        root.right = invertTree(root.right);
        return root;
    }
}
```

### 解法二：迭代
相当于层序遍历，利用队列，逐个结点进行翻转。

```java
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if(root == null)    return null;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty())
        {
            TreeNode cur = q.poll();
            TreeNode temp = cur.left;
            cur.left = cur.right;
            cur.right = temp;
            if(cur.left != null)    q.offer(cur.left);
            if(cur.right != null)   q.offer(cur.right);
        }
        return root;
    }
}
```