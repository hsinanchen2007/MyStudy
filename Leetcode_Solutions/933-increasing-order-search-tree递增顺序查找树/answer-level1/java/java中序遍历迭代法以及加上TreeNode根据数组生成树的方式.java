```java
public TreeNode increasingBST(TreeNode root) {
        if (root == null) {
            return null;
        }
        //获取当前树根，左子树创建出来的就是当前树的根
        TreeNode subRoot = increasingBST(root.left);
        //如果左子树为空，则直接使用当前节点为子树根
        if (subRoot == null) {
            subRoot = root;
        } else {
            //如果左子树创建的树根不为空，则遍历最右侧的叶子节点，将当前的节点挂到最
            //右节点右子树上
            TreeNode subRootTemp = subRoot;
            while (subRoot.right != null) {
                subRoot = subRoot.right;
            }
            subRoot.right = root;
            subRoot = subRootTemp;
        }
        // 获取右子树处理好的根，并赋值给当前节点右子树
        root.right = increasingBST(root.right);
        //清空当前节点的左子树
        root.left = null;
        //返回当前树的根
        return subRoot;
    }
```
并推荐一下java自己实现的根据Integer数组生成树的方式，方便之后做树题测试使用：
```java
public static TreeNode generate(Integer[] a) {
    Queue<TreeNode> queue = new ArrayDeque<>();
    TreeNode root = new TreeNode(a[0]);
    queue.add(root);
    for (int i =1;i<a.length;i+=2) {
            TreeNode treeNode = queue.remove();
            if (a[i] != null) {
                treeNode.left = new TreeNode(a[i]);
                queue.add(treeNode.left);
            }
            if (i + 1 < a.length && a[i + 1] != null) {
                treeNode.right = new TreeNode(a[i + 1]);
                queue.add(treeNode.right);
            }
    }
    return root;
}
```
我们只需要将generate方法放到我们的TreeNode中，使用
```java
TreeNode treeNode = TreeNode.generate(new Integer[] { 5, null, 6, null, 8, 7, 9 });
```
这种方式就可以根据leetCode官方给的数组生成一颗同样的二叉树，方便调试使用

