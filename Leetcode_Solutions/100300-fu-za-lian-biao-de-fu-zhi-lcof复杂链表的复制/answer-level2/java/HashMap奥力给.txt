### 解题思路
第一个双100，C++有指针应该更方便

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
    public Node copyRandomList(Node head) {
        if(head == null) return head;
        
        Node root = head;
        Map<Node, Node> map = new HashMap<>();
        while(root != null){
            Node node = new Node(root.val);
            map.put(root, node);
            root = root.next;
        }
        Node temp = map.get(head);
        Node node = temp;
        while(head != null){
            temp.next = map.get(head.next);
            temp.random = head.random == null ? null : map.get(head.random);
            temp = temp.next;
            head = head.next;
        }
        return node;
    }
}
```