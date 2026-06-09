> 链表反转常用结构 

```java
 1 -> 3 -> 4 -> 5 -> 6 -> null
h/c  tmp

 1 <- 3 <- 4 <- 5 <- 6 
c/h                 pre

pre = null
while(c != null){
    tmp = c.next;

    c.next = pre;
    pre = c;
    c = tmp;
}
```


> 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if(m == n || head == null) return head;
        
        ListNode first = new ListNode(-1);
        first.next = head;
        
        ListNode cur = head, pre = null;
        while(m > 1){
            pre = cur;
            cur = cur.next;
            m--;
            n--;
        }
        
        ListNode l = pre, r = cur;
        while(n > 0){
            ListNode tmp = cur.next;
            
            cur.next = pre;
            pre = cur;
            cur = tmp;
            n--;
        }
        
        if(l == null){
            first.next = pre;
        }else{
            l.next = pre;
        }
        r.next = cur;
        
        return first.next;
        
    }
}
```