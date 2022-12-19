### 解题思路
中序排序的变形。搜索树的最左节点作为链表头节点，最右节点作为链表尾节点。
中序遍历的过程中，准备一个pre和一个cur，pre指向当前节点的前一个节点，在pre和cur之间连线就行。
![image.png](https://pic.leetcode-cn.com/1ff0edfb1a6924bb64b0fa0fdd28f1e050ad626e881e79018d034908d9546e70-image.png)

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
class Solution {    //循环！
    public Node treeToDoublyList(Node root) {
        if(root == null)
            return null;
        LinkedList<Node> stack = new LinkedList<>();
        Node cur = root;
        Node pre = null;    //cur的前一个节点
        Node mostright = root;  //找到最右节点
        while(mostright.right != null){
            mostright = mostright.right;
        }
        boolean flag = true;
        while(cur != null || !stack.isEmpty()){
            while(cur != null){
                stack.push(cur);
                cur = cur.left;
            }
            cur = stack.pop();
            if(flag){
                root = cur;
                pre = root;
                flag = false;
            }
            else{
                pre.right = cur;
                cur.left = pre;
                pre = cur;
            }
            cur = cur.right;
        }
        root.left = mostright;
        mostright.right = root;
        return root;
    }
}
```