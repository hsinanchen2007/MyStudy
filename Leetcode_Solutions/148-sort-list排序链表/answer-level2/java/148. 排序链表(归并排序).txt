### 解题思路
先把链表拆开，通过找中间节点，mid.next==null；拆开
再进行两两排序
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
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        //找中点
        ListNode mid = findMid(head);

        ListNode right = sortList(mid.next);
        mid.next = null;
        ListNode left = sortList(head);
        return merge(left, right);

    }

    private ListNode findMid(ListNode head){
        ListNode fast = head.next;
        ListNode slow = head;
        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }

    private ListNode merge(ListNode h1, ListNode h2){
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        while(h1 != null && h2 != null){
            if(h1.val < h2.val){
                tail.next = h1;
                h1 = h1.next;
                
            }
            else{
                tail.next = h2;
                h2 = h2.next;
                
            }
            tail = tail.next;
        }
        if(h1 != null){
            tail.next = h1;
        }
        if(h2 != null){
            tail.next = h2;
        }
        return dummy.next;
    }
}
```