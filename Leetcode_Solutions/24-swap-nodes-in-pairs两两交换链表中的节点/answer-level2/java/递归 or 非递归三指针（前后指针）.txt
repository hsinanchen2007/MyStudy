#### 递归思想
```java
    public ListNode swapPairs(ListNode head) {
        
        if(head==null||head.next==null){
            return head;
        }
        
        ListNode p = head.next;
        head.next=swapPairs(p.next);
        p.next = head;
        
        return p;
        
    }
```
#### 非递归,三指针法
pre->head->after => pre->after->head

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
    public ListNode swapPairs(ListNode head) {
        
        ListNode p = new ListNode(0);
        ListNode pre = p;
        pre.next = head;
        
        while(head!=null&&head.next!=null){
            ListNode after = head.next;
            pre.next = after;
            head.next =after.next;
            after.next = head;
            pre = head;
            head = pre.next;
        }
        return p.next;
    }
}
# ```