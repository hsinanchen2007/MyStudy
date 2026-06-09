### 解题思路
基本就是树和森林互相转换的思想，二叉树节点的左孩子就是节点孩子，二叉树节点的右孩子，就是节点的兄弟。反过来N叉树的第一孩子节点就是其左孩子，其他孩子节点，就是刚刚那个左孩子节点的全部右子树。

找左孩子的过程其实就是一个深度优先遍历的思想，每一个N叉节点转换为二叉节点后，都往下找其chilren，继续构造下一层的元素。

应该也可以转为非递归模式，这个后面自己会尝试修改成非递归

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Codec {

    public TreeNode encode(Node root) {
        if (root == null){
            return null;
        }
        // 二叉树的root
        TreeNode treeRoot = new TreeNode(root.val);
        // N叉转二叉
        encodeToBinaryTree(treeRoot,root);
        return treeRoot;
    }

    /**
     * N叉树转为二叉树
     * node.children的第一个节点是treeNode.left，其余节点是treeNode.left为root的right子树上
     * @param treeNode 二叉树节点
     * @param node  N叉树节点
     */
    private void encodeToBinaryTree(TreeNode treeNode, Node node){
        if (node.children == null){
            return;
        }
        int i = 0;
        // 这里为什么这样写，因为我不知道这个list是arrayList还是linkedList，用forEach更快一些
        for (Node child : node.children) {
            if (i==0){
                // 第一个孩子设置为treeNode的左孩子
                treeNode.left = new TreeNode(child.val);
                treeNode = treeNode.left;// 往左子树递推
            }else {
                // 其余孩子设置为treeNode.left的右孩子，转换为森林的思想
                treeNode.right = new TreeNode(child.val);
                treeNode = treeNode.right;// 往右子树递推
            }
            // 递归调用，思想其实深度优先遍历
            encodeToBinaryTree(treeNode,child);
            i++;
        }
    }

    // Decodes your binary tree to an n-ary tree.
    // 思路：节点的左孩子作为当前节点孩子的第一个节点，右孩子一直迭代下去到空，全部加入当前节点的孩子List中
    public Node decode(TreeNode root) {
        if (root == null){
            return null;
        }
        // N叉树的根节点
        Node nodeRoot = new Node(root.val,new ArrayList<>());
        // 二叉转N叉
        decodeToNTree(root.left,nodeRoot);
        return nodeRoot;
    }

    /**
     * 二叉树转为N叉树
     * @param treeNode 二叉树节点
     * @param node N叉树节点
     */
    private void decodeToNTree(TreeNode treeNode,Node node){
        //treeNode不空，把treeNode的右孩子全部转换为兄弟节点
        while (treeNode != null){
            // 当前treeNode加入到node.child中
            Node newNode = new Node(treeNode.val,new ArrayList<>());
            node.children.add(newNode);
            // 左子树继续往下走，因为treeNode.left应该在newNode.children中
            decodeToNTree(treeNode.left,newNode);
            // 右子树是newNode的兄弟节点，也就是要设置到node.children中
            treeNode = treeNode.right;
        }
    }

}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(root));
```