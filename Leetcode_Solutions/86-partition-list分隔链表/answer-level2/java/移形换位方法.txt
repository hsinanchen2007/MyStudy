使用的方法是 找到符合的目标 将目标插入到first结点和first.next结点之间。
需要注意的问题是，如果一开头1-2-3-4-5-6 3中1-2满足条件时需要跳过 
使用两个哑巴结点的原因是要d1是用来遍历链表可能会改变，而d2是答案链表

```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        if(head == null) return null;
        
        ListNode d1 = new ListNode(-1);
        ListNode d2 = new ListNode(-2);
        
        d1.next = head;
        d2.next = head;
        
        ListNode cur = d1, first = d2;
        
        while(cur.next != null){
            if(first.next.val < x){
                first = first.next;
                cur = cur.next;
                continue;
            }
            if(cur.next.val < x){
                ListNode target = cur.next;
                
                cur.next = target.next;
                target.next = first.next;
                
                
                first.next = target;
                first = first.next;
            }
            else{
                cur = cur.next;
            }
        }
        
        return d2.next;
    }
}
```
