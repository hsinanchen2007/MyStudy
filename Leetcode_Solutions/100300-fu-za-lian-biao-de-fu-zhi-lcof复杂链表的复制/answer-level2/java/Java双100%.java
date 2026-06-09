```
class Solution {
    public Node copyRandomList(Node head) {
        if(head == null){
            return null;
        }
        Node cur = head, next = null;   //cur用于遍历，next记录后面的位置
        while(cur != null){     //第一遍，对每个结点生成对应的copyNode，插在当前结点后面
            next = cur.next;
            Node copyNode = new Node(cur.val);
            copyNode.next = cur.next;
            cur.next = copyNode;
            cur = next;
        }
        cur = head;
        while(cur != null){     //第二遍，设置copyNode的random指针
            next = cur.next.next;
            cur.next.random = cur.random != null ? cur.random.next : null;  //判断，防止空指针异常
            cur = next;
        }
        cur = head;
        Node newHead = cur.next;
        while(cur != null){     //第三遍，将原链表和复制链表拆开，一分为二
            next = cur.next;
            cur.next = next != null ? cur.next.next : null; //最后位置判断，防止空指针异常
            cur = next;
        }
        return newHead;
    }
}
```
