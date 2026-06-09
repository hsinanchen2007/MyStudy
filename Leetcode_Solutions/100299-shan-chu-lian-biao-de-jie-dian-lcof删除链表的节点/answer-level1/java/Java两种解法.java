# 使用空节点
```java
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        ListNode beforeHead = new ListNode(-1);
        beforeHead.next = head;
        ListNode p = beforeHead;
        
        if(head == null)
        {
            return head;
        }

        while(beforeHead.next != null)
        {
            if(beforeHead.next.val == val)
            {
                beforeHead.next = beforeHead.next.next;
            }
            else
            {
                beforeHead = beforeHead.next;
            }
        }
        return p.next;
    }
}
```

# 不利用空表头指向，但是要利用空表头输出
```java
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        ListNode beforeHead = new ListNode(-1);
        beforeHead.next = head;
        if(head.val == val)
        {
            beforeHead.next = head.next;
        }
        if(head == null)
        {
            return head;
        }
        while(head.next != null)
        {
            if(head.next.val == val)
            {
                if(head.next.next != null)
                    head.next = head.next.next;
                else
                {
                    head.next = null;
                    break;
                }
            }
            head = head.next;   
        }
        return beforeHead.next;
    }
}
```







# 判断中包括表头，直接寻找到需要删除的节点
```java
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        ListNode prev = new ListNode(-1);
        ListNode result = prev;
        prev.next = head;
        while(prev.next != null && prev.next.val != val)
            prev = prev.next;
        prev.next = prev.next.next;
        return result.next;
    }
}
```
