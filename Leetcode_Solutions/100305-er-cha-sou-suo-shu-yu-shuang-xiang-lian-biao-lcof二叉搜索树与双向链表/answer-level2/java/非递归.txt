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
    public Node treeToDoublyList(Node root) {
        if(root == null) return null;
        Node newhead = helper(root);
        //创建头尾相连
        Node temp = newhead;
        while(temp.right != null){
            temp = temp.right;
        }
        //进行头尾相连
        temp.right = newhead;
        newhead.left = temp;
        return newhead;
    }
    //转换为双向不循环链表
    public Node helper(Node root){
        if(root == null) return null;
        if(root.left != null){
            //找到最小的值
            Node left = helper(root.left); 
            while(left.right != null) left = left.right;
            //进行小值双向赋值
            root.left = left;
            left.right = root;
        }
        if(root.right != null){
            Node right = helper(root.right);
            //进行大值双向赋值
            root.right = right;
            right.left = root;
        }
        while(root.left != null){
            root = root.left;
        }
        return root;
    }
}
```