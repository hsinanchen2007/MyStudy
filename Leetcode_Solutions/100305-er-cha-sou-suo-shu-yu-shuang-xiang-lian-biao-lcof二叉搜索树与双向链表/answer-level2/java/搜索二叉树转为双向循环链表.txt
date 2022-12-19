### 解题思路
此处撰写解题思路
需要一个头指针和一个尾指针，便于便面的循环连接操作；为了使得二叉树变得有序，所以按照中序遍历，使得左子树有序，左子树最后的节点连接右子树的第一个节点然后使得右子树也变得有序，因为有额外的连接操作因此需要额外的函数，***上的是双向链表没有循环操作

递归出口： 如果root==null，退出
递归操作：遍历左子树节点直到左子树最左端的节点，如果尾节点为空，则将head指向此时的root（仅这第一次操作），并且将tail也指向root便于之后的连接操作；第二次以后tail不为null，就进行连接操作，使得局部左子树有序，有序之后再进行遍历右子树。
完成双向链表操作后，还需要将首尾相连（如果是***那道题就不需要了），head之前是right指向root，因此此时head.left指向tail，同理tail的right指向head
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
    public Node head, tail;
    public void process(Node root){
        if(root == null){
            return;
        }
        process(root.left);
        if(tail != null){
            tail.right = root;
            root.left = tail;
        }else{
           head = root;
        }
        tail = root;
        process(root.right);
    }
    public Node treeToDoublyList(Node root) {
        if(root == null){
            return null;
        }
        process(root);
        tail.right = head;
        head.left = tail;
        return head;
    }
}
```