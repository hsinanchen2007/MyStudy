### 解题思路
此处撰写解题思路

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
    // 中序遍历，访问该节点的时候，对其做如下操作：
    // 1.将当前被访问节点curr的左孩子置为前驱pre（中序）
    // 2.若前驱pre不为空，则前驱的右孩子置为当前被访问节点curr
    // 3.将前驱pre指向当前节点curr，即访问完毕

    // 上述形成的是一个非循环的双向链表
    // 需进行头尾相接
    Node pre=null;

    public Node treeToDoublyList(Node root) {
        if(root==null) return root;
        Node p=root,q=root;
        while(p.left!=null) p=p.left;
        while(q.right!=null) q=q.right;
        inorder(root);
        p.left=q;
        q.right=p;
        return p;
    }
    public void inorder(Node curr){
        if(curr==null) return;
        inorder(curr.left);

        curr.left=this.pre;
        if(this.pre!=null) this.pre.right=curr;
        pre = curr;

        inorder(curr.right);
    }
}
```