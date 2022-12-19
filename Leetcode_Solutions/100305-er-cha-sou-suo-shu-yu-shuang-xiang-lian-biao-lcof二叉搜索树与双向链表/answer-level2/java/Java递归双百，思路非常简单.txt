![WechatIMG4.png](https://pic.leetcode-cn.com/cd562f22fc8bce07ed97a22d80da0e0e746832a197b225270cd47ed45d6f6f34-WechatIMG4.png)
### 解题思路
思路就是中序遍历，在中序遍历的时候需要记住前一个节点，不然没法连起来，并且也要记住尾结点，然后头尾链接一下即可。
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
    public  Node newHead = null;
    public  Node pre = null;
    public Node treeToDoublyList(Node root) {
          if(root == null)
            return root;
        inOrder(root);
        newHead.left = pre;
        pre.right = newHead;
        return newHead;
    }
     public void inOrder(Node root){
        if(root == null)
            return;
        inOrder(root.left);
        Node head = new Node(root.val);
        if(newHead == null)
            newHead = head;
        head.left = pre;
        if(pre != null)
            pre.right = head;
        pre = head;
        inOrder(root.right);
    }
}
```