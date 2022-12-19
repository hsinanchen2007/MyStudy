全局变量prev 指当前指针的前一位 

递归过程中，递归到底部后，将head节点插入到之前的prev节点的前面

具体过程是：

1.记录prev的next Node next = prev.next

2.将head放到prev的next: prev.next = head

3.将之前的prev的next接到head的next:head.next=next

4.将next的prev指向head:next.prev = head

```
class Solution {
    Node prev = null;
    public Node flatten(Node head) {
        prev = new Node(0,null,null,null);
        post(head);
        return prev.next;
    }

    public void post(Node head){
        if(head==null) 
            return;
        post(head.next);
        post(head.child);
        head.child = null;
        
        Node next = prev.next;
        prev.next = head;
        head.next = next;
        if(next != null)
            next.prev = head;
        
    }
}
```