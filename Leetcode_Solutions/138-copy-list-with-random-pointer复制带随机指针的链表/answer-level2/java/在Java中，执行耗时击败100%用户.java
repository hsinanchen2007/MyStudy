### 解题思路
思路就是先复制next指针，再复制random指针，最后将链表恢复原样，将newHead返回。
1->2->3->null 变成1->1'->2->2'->3->3'->null。然后1'的random指针可以通过1.random.next找到。不用回头，一直向前走即可。

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
            return head;
         Node cur = head;
        //复制next指针
        while(cur != null){
            Node temp = new Node(cur.val);
            Node next = cur.next;
            cur.next = temp;
            temp.next = next;
            cur = next;
        }
        //复制random指针
        cur = head;
        while(cur != null){
            cur.next.random = cur.random == null ? null : cur.random.next;
            cur = cur.next.next;
        }
        //将copy的拿下来，恢复原来的链表
        Node newHead = head.next;
        Node curNew = newHead;
        cur = head;
        while(cur.next.next != null){
            Node next = cur.next.next;
            cur.next = next;
            cur = next;
            curNew.next = cur.next;
            curNew = curNew.next;
        }
        cur.next = null;
        return newHead;
    }
}
```