### 解题思路
利用头结点化简代码；
遍历过程中保存需要连接的节点，
reverse反转+接尾，完成反转后再拼接链表。

### 代码

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
        ListNode dummy = new ListNode(0);
        int k = n-m;
        dummy.next = head;
        ListNode cur = dummy, start, first, r;
        
        if(m == n) return head;
        while(m > 1)
        {cur = cur.next; m--;}
        start = cur; first = cur.next;
        while(k >= 0)
        {cur = cur.next; k--;}

        if(cur.next == null) r = reverse(first,null);
        else{ListNode end = cur.next; cur.next = null; r = reverse(first,end);}
        start.next = null; start.next = r;
        return dummy.next;
    }

    private ListNode reverse(ListNode x,ListNode l2){
        ListNode r = l2, l =x, t = null;
        while(l != null)
        {t = l.next; l.next = r; r = l; l = t;}
        return r;
    }
    
}
```