1. 在 head.child 非空的地方 DFS

2. 这题有两个坑点是：DFS 后 child 指针要设为 null，并且维护 head.next.prev 时要判断 head.next 是否为空
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/
class Solution {
    public Node flatten(Node head) {
        if (head == null) return head;
        Node dummy = new Node(0, null, head, null);
        
        while (head != null)
        {
            if (head.child == null)
            {
                head = head.next;
                continue;
            }
            Node next = head.next;
            head.next = flatten(head.child);
            head.next.prev = head;
            head.child = null;
            while (head.next != null) head = head.next;
            head.next = next;
            if (next != null) head.next.prev = head;
            head = head.next;
        }
        return dummy.next;
    }
}```