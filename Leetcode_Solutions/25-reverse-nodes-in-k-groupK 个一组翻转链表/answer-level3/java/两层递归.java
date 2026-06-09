在外层是判断是否满足翻转的条件：

(1)不满足直接返

(2)满足需要进行翻转的区间的首位节点[head, tail],并记录下tail.next进行递归。

(3)将head和tail区间进行翻转，翻转之后head为翻转区间的尾节点、tail为头结点。所以讲head.next指向递归的结果。

(4)返回头结点tail

```
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode tail = head;
        int count = 0;
        while (tail != null && count < k) {
            count++;
            if (count == k) break;
            tail = tail.next;
        }
        if (count < k) return head;
        
        
        ListNode newHead = tail.next;
        once(head,tail);
        head.next = reverseKGroup(newHead, k);
        return tail;
    }
    
    private ListNode once(ListNode head, ListNode tail) {
        if (head == tail) return head;
        
        ListNode last = once(head.next,tail);
        last.next = head;
        head.next = null;
        return head;
    }
}
```
