### 解题思路
剑指offer的思路，时间复杂度O(n)，空间复杂度O(1)
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
        copyNode(head);
        setRandomNode(head);
        return getCopyNodes(head);
    }
    
    private Node copyNode(Node head) {
        if (head == null) {
            return null;
        }
        Node node = new Node(head.val);
        node.next = copyNode(head.next);
        head.next = node;
        return head;
    }
    
    private void setRandomNode(Node head) {
        if (head == null) {
            return;
        }
        Node cur = head;
        while (cur != null) {
            Node next = cur.next;
            if(cur.random != null) {
                next.random = cur.random.next;
            }
            cur = next.next;
        }
    }
    
    private Node getCopyNodes(Node head) {
        if (head == null) {
            return null;
        }
        Node origin = head;
        Node copyHead = head.next;
        Node cur = origin.next;
        while (cur.next != null) {
            Node next = cur.next;
            origin.next = next;
            cur.next = next.next;
            origin = origin.next;
            cur = cur.next;
        }
        origin.next = null;
        return copyHead;
    }
}
```