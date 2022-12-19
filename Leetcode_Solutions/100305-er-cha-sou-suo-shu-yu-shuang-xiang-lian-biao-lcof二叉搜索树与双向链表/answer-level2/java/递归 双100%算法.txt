### 解题思路
执行用时 : 0 ms , 在所有 Java 提交中击败了 100.00% 的用户 
内存消耗 : 39.8 MB , 在所有 Java 提交中击败了 100.00% 的用户

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
    public Node treeToDoublyList(Node root) {
        if(root==null){
            return null;
        }
        //只有一个节点，那么左右都指向自己
        if(root.left==null && root.right==null){
            root.left= root;
            root.right = root;
            return root;
        }

        //处理左边
        Node left = treeToDoublyList(root.left);
        if(left!=null){
            Node leftTail = left.left;
            leftTail.right = root;
            root.left = leftTail;
        }else{
            left = root;
        }

        //处理右边
        Node right = treeToDoublyList(root.right);
        Node rightTail;
        if(right!=null){
            rightTail = right.left;
            root.right = right;
            right.left = root;
        }else{
            rightTail = root;
        }

        //右边的尾部 和 左边的头部连接起来
        rightTail.right = left;
        left.left = rightTail;
        //返回左边的头部
        return left;
    }
}
```