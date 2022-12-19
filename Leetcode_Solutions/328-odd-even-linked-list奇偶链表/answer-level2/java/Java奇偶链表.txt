遍历，用 odd,even 去维持奇数索引、偶数索引链表；最后，连接起来。

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
    public ListNode oddEvenList(ListNode head) {
        ListNode odd = new ListNode(0);
        ListNode oddDummy = odd;
        ListNode even = new ListNode(0);
        ListNode evenDummy = even;
        while(head !=null){
            odd.next = head;
            even.next = head.next;
            odd = head;
            even = head.next;
            if(head.next!=null){
                head = head.next.next;
            }
            else{
                break;
            }
        }
        odd.next = evenDummy.next;
        return oddDummy.next;
    }
}
```
