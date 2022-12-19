![Snipaste_2020-02-07_15-23-47.png](https://pic.leetcode-cn.com/2db00ba0b0649cf6506e0f1972ff42301a1be9d9483a0072d24fbae94deac91b-Snipaste_2020-02-07_15-23-47.png)

题目中提到了，删除给定值的叶子节点后，可能会出现新的值是target的叶子节点，所以为了再叶子节点判值并删除后才对上一级节点进行判值操作，需要用到后序遍历，因为后序遍历的根节点遍历就是在对子树遍历后才完成的，代码很简单，需要注意的是删除节点的操作我这里是用返回值的形式实现的，所以在首次调用递归函数时需要手动将递归函数返回值赋值给root，才不会在整棵树都需要删除时返回一个根节点而不是null
```
class Solution {
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        root = postOrder(root, target);
        return root;
    }
    public TreeNode postOrder(TreeNode node, int target) { // 后序遍历判值，可以应对动态生成的叶子节点
        if(node.left != null) { // 对左节点递归
            node.left = postOrder(node.left, target);
        }
        if(node.right != null) { // 对右节点递归
            node.right = postOrder(node.right, target);
        }
        if(node.val == target && node.left == null && node.right == null) { // 最后判值
            return null;
        }
        return node;
    }
}
```

