### 解题思路
根据next指针遍历每一个原链表元素，借助辅助map，获得每个元素的复制元素，修改复制元素的next、random指针，返回原链表head的复制元素。

### 代码

```java
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/
class Solution {
    Map<Node, Node> map = new HashMap();
    public Node copyRandomList(Node head) {
        if (head == null) return null;
        Node ptr = head;
        while(ptr != null) {
            Node node = getNode(ptr);
            node.next = getNode(ptr.next);
            node.random = getNode(ptr.random);
            ptr = ptr.next;
        }
        return getNode(head);

    }

    private Node getNode(Node node) {
        if (node == null) return null;
        if (!map.containsKey(node)) {
            Node tmp = new Node(node.val);
            map.put(node, tmp);
        }
        return map.get(node);
    }
}
```