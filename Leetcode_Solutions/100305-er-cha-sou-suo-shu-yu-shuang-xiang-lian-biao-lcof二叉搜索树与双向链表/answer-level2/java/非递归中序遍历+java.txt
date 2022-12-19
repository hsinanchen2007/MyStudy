### 解题思路

二叉搜索树的中序遍历就是一个有序的序列，所以利用Stack实现中序遍历；需要注意的地方是中序遍历是在stack弹出元素的时候访问元素，并寻找下一个元素，在该题中需要先完成这个传递过程，再去利用节点去构建循环链表

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
        return selfTreeToDoublyList(root);
    }
    

    private Node selfTreeToDoublyList(Node root) {
        if (root == null) {
            return null;
        }
        
        Stack<Node> stack = new Stack<>();
        
        Node iter = root, preNode = null, nowNode = null, head = null;
        while(!stack.isEmpty() || iter != null) {
            if (iter == null) {
                //完成访问和传递
                iter = stack.pop();
                nowNode = iter;
                iter = iter.right;

                //构建链表
                if (preNode == null) {
                    head = nowNode;
                } else {
                    nowNode.left = preNode;
                    preNode.right = nowNode;
                }
                preNode = nowNode;
                
            } else {
                stack.push(iter);
                iter = iter.left;
            }
        }

        //首尾相连
        nowNode.right = head;
        head.left = nowNode;

        return head;
    }

}
```