##原地交换解法
```
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if(head == null) return null;
        ListNode odd = head;
        ListNode even = head.next;
        while(odd != null && even != null) {
            ListNode temp = even.next;
            if(temp == null) break;
            even.next = temp.next;
            temp.next = odd.next;
            odd.next = temp;
            odd = odd.next;
            even = even.next;
        }
        return head;
    }
}
```

##创建odd链表，even链表，最后连接
```
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if(head == null) return null;
        ListNode odd = head, even = head.next;
        ListNode dummy = new ListNode(-1);
        dummy.next = even;
        int i = 1;
        while(even != null && even.next != null) {
            if(i % 2 == 1) {
                odd.next = even.next;
                odd = odd.next;
            }
            else {
                even.next = odd.next;
                even = even.next;
            }
            i++;
        }
        odd.next = dummy.next;
        return head;
    }
}
```


