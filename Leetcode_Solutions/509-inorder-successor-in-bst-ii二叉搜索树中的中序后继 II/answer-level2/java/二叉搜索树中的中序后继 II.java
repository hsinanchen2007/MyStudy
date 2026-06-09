### 思路
前提我们没有办法获取到树结构
对于中序遍历来说，当前节点的下一个节点分为下面两种情况
1. 当前节点是根节点或者当前节点有右子树：此时当前节点的后继为右子树中最左边的节点
2. 当前节点是右节点，此时后继为其第一个作为左孩子的祖先节点
![WechatIMG2.jpeg](https://pic.leetcode-cn.com/0297b5f4ed2e18f74918ff8d1e0f87a622dd765b3e231509667faa44e1b4caad-WechatIMG2.jpeg)
如图中的 C 节点，它是一个右节点，那么它的后继是：第一个作为左子树的祖先的父节点，即 B 的父节点 A
### 代码
```
public Node inorderSuccessor(Node node) {
    /// case 1
    if (node.parent == null || node.right != null) {
        Node temp = node.right;
        while (temp != null && temp.left != null) {
            temp = temp.left;
        }
        return temp;
    }
    /// case 2
    if (node == node.parent.right) {
        Node temp = node.parent;
        while (temp != null && temp.parent != null && temp != temp.parent.left) {
            temp = temp.parent;
        }
        return temp.parent;
    }
    return node.parent;
}
```