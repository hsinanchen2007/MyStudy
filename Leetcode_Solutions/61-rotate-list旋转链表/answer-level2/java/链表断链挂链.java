
> 草图

![image.png](https://pic.leetcode-cn.com/d0e3528b2a15069e9c2c6b82875152de32d7d91c2baa178508921c9b34b58280-image.png)



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
    int n = 0;
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null) return head;
        
        ListNode first = new ListNode(-1);
        first.next = head;
        
        // 计算链表的长度
        while(head != null){
            n++;
            head = head.next;
        }        
        
        // 避免k比链表还大, 所以取模
        k = k % n;
        if(k%n == 0) return first.next;
        
        int movestep = n - k;
        ListNode cur = first.next;
        ListNode tail = cur;
        
        //first -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null
        //        c/t
        while(--movestep>0){
            cur = cur.next;
        }
        
        //first -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null
        //                        c    t
        tail = cur.next;
        while(tail != null && tail.next != null){
            tail = tail.next;
        }
        
        //first -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null
        //        oh              c    t
        ListNode oldhead = first.next;
        
        first.next = cur.next;
        tail.next = oldhead;
        cur.next = null;
        
        return first.next;
    }
}
```