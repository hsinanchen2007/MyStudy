### 解题思路
链表长度小于2则直接返回head。用temp保存第三个节点等会儿递归，res保存第二个节点用于答案返回，交换前两个节点。让第一个节点指向swapPairs(temp)的返回

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
        if(head==null||head.next==null)
            return head;
        ListNode pre=head;
        ListNode current=head.next;
        ListNode res=current;
        ListNode temp=current.next;
        current.next=pre;
        pre.next=swapPairs(temp);
        return res;

        
    }
}
```