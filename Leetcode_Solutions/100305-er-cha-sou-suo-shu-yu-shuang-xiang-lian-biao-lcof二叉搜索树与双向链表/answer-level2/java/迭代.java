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
        if (root == null)
            return null ;
        Stack<Node> stack = new Stack<Node>() ;
        Node head = root ;
        Node preNode = root ;
        Node curNode = root;
        boolean onceFlag = true ;
        while(!stack.isEmpty() || curNode != null) {
            while (curNode != null ) {
                stack.push(curNode) ;
                curNode = curNode.left ;
            }

            if (!stack.isEmpty()) {
                curNode = stack.pop() ;
                if (onceFlag) {
                    head = curNode ;
                    onceFlag = false ;
                } else {
                    preNode.right = curNode ;
                    curNode.left = preNode ;
                }
                preNode = curNode ;
                curNode = curNode.right ;
            } 
        }

        preNode.right = head ;
        head.left = preNode ;
        return head ;
    }
}
```