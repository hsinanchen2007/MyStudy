### 解题思路
核心思路：二叉搜索树的中序遍历即为数据的升序排列
### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
    //head用于记录头结点；prev记录前一个节点，用于处理双向指针（当递归结束时，prev为整个数据的tail，所以不需要额外申请tail变量）
    Node head=null,prev=null;
    public Node treeToDoublyList(Node root) {
        if(root==null){
            return null;
        }
        inOrder(root);
        //处理双向链表头尾的连接关系
        head.left=prev;
        prev.right=head;
        return head;
    }

    //中序遍历
    private void inOrder(Node node){
        //左子树
        if(node.left!=null){
            inOrder(node.left);
        }
        //根节点
        if(head==null){
            head=node;
        }else{
            prev.right=node;
            node.left=prev;
        }
        //向后移动prev节点
        prev=node;
        //右子树
        if(node.right!=null){
            inOrder(node.right);
        }
    }
}
```