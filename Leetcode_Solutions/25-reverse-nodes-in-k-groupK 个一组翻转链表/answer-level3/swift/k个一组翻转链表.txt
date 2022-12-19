
题解思路-：

以K=2为例，

0->1->2->3->4->5->6->7

0->2->1->4->3->6->5->7

将原链表拆分成若干个小链表依次进行翻转，根据K获取小链表翻转区间，当剩下未翻转链表个数小于K，则不翻转，返回

```
class Solution {

    func reverse(_ head : ListNode?) -> ListNode {
        var current : ListNode? = head;
        var pre : ListNode? = nil;
        while current != nil {
            let next : ListNode? = current?.next;
            current?.next = pre;
            pre = current;
            current = next;
        }
        return pre!;
    }
    
    func reverseKGroup(_ head: ListNode?, _ k: Int) -> ListNode? {
        let dump = ListNode.init(0);
        dump.next = head;
        
        var pre : ListNode? = dump
        var end : ListNode? = dump
                
        while (end?.next != nil) {
            for _ in 0...k {
                if end == nil {
                    break;
                }
                end = end?.next
            }
            if end == nil {
                break;
            }
            let start : ListNode? = pre?.next;
            let next : ListNode? = end?.next;
            end?.next = nil;
            pre?.next = reverse(start)
            start?.next = next;
            pre = start;
            end = pre;
        }
        return dump.next;
    }
}
```
