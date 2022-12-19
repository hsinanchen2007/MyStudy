# 思路(迭代)

删除节点, 关键点在于找到节点keyNode的同时, 记录下删除节点的父节点parent.
最后通过将parent.left = keyNode.right(不一定, 这里仅仅是举个例子)将父节点指向keyNode的左孩子或者右孩子.

边界情况一共三种, 实际为两种(原因如下).

- 删除节点的左孩子与孩子都不为空树, 可以在找到删除节点后与其后继或者前驱交换位置, 从而将问题转化为下面两种更平凡的情况. 这里问题转化成如何找前驱与后继, 以及如何更新前驱与后继的父节点.
- 删除节点keyNode的左孩子为空树, 右孩子不为空树. 修改父节点的左(右)孩子parent.right = keyNode.right 或者 parent.left = keyNode.right.
- 删除节点的左孩子不为空树, 右孩子为空树.修改父节点的左(右)孩子parent.right = keyNode.left 或者 parent.left = keyNode.left.

# JAVA CODE
```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    //哨兵节点, 
    private TreeNode parent = new TreeNode(-1);
    //parent节点数据更新方向, 1为left, -1为right
    private int dir;
    
    public TreeNode deleteNode(TreeNode root, int key) {
        parent.left = root;
        TreeNode head = this.parent; // 记录root所在的位置
        
        // search方法每次查找节点时, 会更新该节点对应的父节点
        TreeNode keyNode = searchBST(root,key,this.parent);
        if(keyNode == null) return root;
        
        //找到的keyNode有两个子树, 有两种解法方案, 用中序前驱替换之, 或者中序后继替换之. 这里选用后继元素替换keyNode.
        //注意, 找到successor后, 该后继一定是一颗没有左孩子的BST, 为了删除该后继, 需要找到后继的parent(这点很重要)
        //找到后继后, 可以将问题属于更平凡的 无子树问题 从而统一解决.
        TreeNode successor = null;
        if(keyNode.left != null && keyNode.right != null) {
            // 用中序前驱替换, 即找到左子树的Left-most successor.
            successor = getLeftMostNode(keyNode.right);
            // 通过在keyNode所在的子树中, 查找后继从而更新一下后继的parent
            successor = searchBST(keyNode, successor.val, null);
            // 交换后继与删除节点的位置
            int tmp = keyNode.val;
            keyNode.val = successor.val;
            successor.val = tmp;
            keyNode = successor;
        }
        
        
        this.dir = (this.parent.left != null && this.parent.left.val == key) ? 1: -1;
        if(keyNode.left == null){
            successor = keyNode.right;
            if(this.dir == 1) this.parent.left = successor;
            if(this.dir == -1) this.parent.right = successor;
        }else if(keyNode.right == null){
            successor = keyNode.left;
            if(this.dir == 1) this.parent.left = successor;
            if(this.dir == -1) this.parent.right = successor;
        }
        
        // 哨兵节点的左侧始终指向root
        return head.left;
    }
    
    // 沿着根结点, 找到根结点所在最左侧通路上的所有节点, 依次压入栈中
    // 栈顶节点即为最左侧通路的最左侧节点
    public TreeNode getLeftMostNode(TreeNode root){
        Stack<TreeNode> subtree = new Stack();
        TreeNode curr = root;
        while(curr != null){
            subtree.push(curr);
            curr = curr.left;
        }
        return subtree.pop();
    }
    
    // 查找key的同时, 更新key所在节点的parent.
    public TreeNode searchBST(TreeNode root, int key, TreeNode parent){
        if(root == null) return null;
        if(key == root.val) return root;
        this.parent = root;
        return key < root.val ? searchBST(root.left,key,this.parent) : searchBST(root.right,key,this.parent);
    }
}
```
