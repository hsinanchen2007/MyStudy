```java
class Solution {
    public Node copyRandomList(Node head) {
        // 1. 复制
        if(head == null) return null;
        Node cur = head;
        while(cur != null){
            Node temp = cur.next;
            cur.next = new Node(cur.val,null,null);
            cur.next.next = temp;
            cur = temp;
        }
        // 2. 置随机指针
        cur = head;
        while(cur != null){
            if(cur.random != null) cur.next.random = cur.random.next;  
            cur = cur.next.next;
        }
        // 3. 拆分
        cur = head;
        Node copy_head = cur.next;
        Node copy_cur = cur.next;
        while(copy_cur.next != null){
            cur.next = cur.next.next;
            cur = cur.next;
            copy_cur.next = copy_cur.next.next;
            copy_cur = copy_cur.next;
        }
        // 4. 给 cur 加上 null
        cur.next = null;
        return copy_head;
    }
}
```