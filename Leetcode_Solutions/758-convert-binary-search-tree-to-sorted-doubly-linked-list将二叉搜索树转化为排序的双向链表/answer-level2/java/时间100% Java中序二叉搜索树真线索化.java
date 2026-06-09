### 解题思路
类似二叉树的线索化，使用指针pre保存前一个node的信息，inOrder进行中序遍历
设置起始pre值为Integer.MIN_VALUE,首先中序找到头节点，并更新pre，将头节点保存在head中，之后将pre赋为头节点。
之后每次中序遍历出一个节点，将pre的right指向该root，并将root的left指向pre，设置pre指向当前节点并设置end指向该节点
end用来保存最后一个节点的信息，最后直接使用pre也可以，为了清晰就多加个节点。
时间100

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

    public static Node head;
    public static Node end;
    public static Node pre;

    public Node treeToDoublyList(Node root) {
        if(root == null) return null;
        if(root.left == null && root.right == null){
            root.left = root;
            root.right = root;
            return root;
        }
        pre = new Node(Integer.MIN_VALUE, null, null);
        inOrder(root);
        end.right = head;
        head.left = end;
        return head;
    }

    public void inOrder(Node root){
        if(root == null) return;
        if(root.left != null) inOrder(root.left);
        if(pre.val == Integer.MIN_VALUE) {
            pre = root;
            head = root;
        }

        else{
            pre.right = root;
            root.left = pre;
            pre = root;
            end = root;
        }
        if(root.right != null) inOrder(root.right);
    }
}
```