### 解题思路
/**
 * 思路
 * 1.如果在两个结点以内，直接返回空，结束
 * 2.找到终点，反转后半部分，进行插入
 */

### 代码

```java
class Solution {
    public void reorderList(ListNode head) {
        if(head== null || head.next == null || head.next.next==null) return ;

        ListNode slow = head;
        ListNode fast = head;
        while(fast!=null && fast.next!=null && fast.next.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }

        fast = reverseList(slow.next);//后半部分颠倒
        slow.next = null;
        slow = head;

        while(fast!=null){
            ListNode fNext = fast.next;
            ListNode slNext = slow.next; 
            slow.next = fast;
            fast.next = slNext;

            slow = slNext;
            fast = fNext;
        }   
    }
    public ListNode reverseList(ListNode head){
        if(head == null || head.next == null) return head;
        ListNode prev= null ;
        ListNode curr= head;
        while(curr!=null){
            ListNode nextTemp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
}
```