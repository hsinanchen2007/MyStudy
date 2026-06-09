### 解题思路
保存好头节点！

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
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode res = dummy;
        while (head.next != null){
            ListNode temp1 = head;
            ListNode temp2 = head.next;
            dummy = swapNode(dummy,temp1,temp2);
            head = dummy.next;
            if (head == null)
                break;
        }
        return res.next;
    }

    private ListNode swapNode(ListNode head,ListNode i,ListNode j){
        ListNode res = j.next;
        j.next = i;
        i.next = res;
        head.next = j;
        return i;
    }
}
```