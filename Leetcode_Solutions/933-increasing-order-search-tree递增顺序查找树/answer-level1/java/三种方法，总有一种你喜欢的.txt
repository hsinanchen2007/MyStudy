先中序遍历保存所有节点值到一个集合中，在通过递归创建一个递增顺序查找树
```java
public class Solution {
    List<Integer> list = new ArrayList<>();

    public TreeNode increasingBST(TreeNode root) {
        if (root == null) {
            return null;
        }
        inOrder(root);
        return dfs(0, list.size() - 1);
    }

    private TreeNode dfs(int l, int r) {
        if (l > r) {
            return null;
        }

        TreeNode newTree = new TreeNode(list.get(l));
        newTree.right = dfs(++l, r);
        return newTree;
    }

    private void inOrder(TreeNode node) {
        if (node == null) {
            return;
        }
        inOrder(node.left);
        list.add(node.val);
        inOrder(node.right);
    }
}
```

从官方答案中受的启发，很巧妙的一种解法
```java
public class Solution {
    TreeNode pre;
    public TreeNode increasingBST(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode ret = new TreeNode(-1);
        pre = ret;
        inOrder(root);

        return ret.right;
    }
    private void inOrder(TreeNode node) {
        if (node == null) {
            return;
        }
        inOrder(node.left);
        node.left = null;
        pre.right = node;
        pre = node;
        inOrder(node.right);
    }
}
```
递归+引用传递
```java
public class Solution {
    public TreeNode increasingBST(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode newLeftTree = increasingBST(root.left);
        TreeNode newRightTree = increasingBST(root.right);
        root.left = null;
        if (newLeftTree == null) {
            root.right = newRightTree;
            return root;
        }
        if (newRightTree == null) {
            newLeftTree.right = root;
            return newLeftTree;
        }

        TreeNode cur = newLeftTree;
        while (cur.right != null) {
            cur = cur.right;
        }
        cur.right = root;
        root.right = newRightTree;
        return newLeftTree;
    }
}

```