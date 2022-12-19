### 思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :38.4 MB, 在所有 Java 提交中击败了100.00%的用户
利用链表存储中序遍历节点

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
    List<Node> inList = new ArrayList<>();
    public Node treeToDoublyList(Node root) {
        if(root == null){
            return root;
        }
        if(root.left == null && root.right == null){
            root.left = root;
            root.right = root;
            return root;
        }
        inorder(root.left,inList);
        inList.add(root);
        inorder(root.right,inList);
        int length = inList.size();
        int i = 0;
        while(i < length - 1){
            Node node1 = inList.get(i);
            Node node2 = inList.get(i + 1);
            node1.right = node2;
            node2.left = node1;
            i++;
        }
        Node head = inList.get(0);
        Node node = inList.get(inList.size()-1);
        node.right = head;
        head.left = node;
        return head;
    }
    public void inorder(Node root, List<Node> list){
        if(root == null){
            return;
        }
        inorder(root.left,inList);
        list.add(root);
        inorder(root.right,inList);

    }
}
```