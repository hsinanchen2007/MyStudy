### 解题思路
先创建不带随机指针的普通链表。然后遍历原链表，根据随机指针和当前指针的位置来生成新链表的随机指针。

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
        if(head == null)
            return null;

        Node tail = head;

        Node newhead = new Node(tail.val);
        Node p = newhead;
        tail = tail.next;

        while(tail != null){
            Node q = new Node(tail.val);
            q.next = null;
            p.next = q;
            p = p.next;
            tail = tail.next;
        }

        tail = head;
        p = newhead;

        while(tail != null){
            Node tmp = tail.random;
            if(tmp == null){
                p.random = null;
            }
            else{
                Node q = head;
                Node t = newhead;
                while(q != tmp){
                    q = q.next;
                    t = t.next;
                }
                p.random = t;
            }
            tail = tail.next;
            p = p.next;
        }
        return newhead;
    }
}
```