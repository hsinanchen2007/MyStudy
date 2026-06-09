### 解题思路
这一题主要从反转链表I中延续过来。从反转链表中，我们可以知道最终状态，prev指向了新的头，cur和next会指向老的链表的最后一位。
因此答案分为三个部分： 老的链表直到m，反转后的链表m到n，老的链表n以后的部分。 分别找出他们，然后拼接。

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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if(m == n) return head;
        //一个for循环到需要的位置，call reverse，反转n个，然后return头
        ListNode target = head;
        ListNode start = null, end = null, newHead = head;
        for(int i = 1; i < n; i++ ){
            //将newHead指向需要反转的前一位
            if(i > 1 && i == m - 1) newHead = target;
            if(i == m) start = target;
            target = target.next;
        }
        end = target;
        //System.out.println(start.val+"||"+end.val+"||"+newHead.val);
        ListNode result = reverseTarget(start,end);
        //拼接一下，如果需要反转的部分包含了head，那么直接返回result就好
        if(start == newHead) return result;
        newHead.next = result;
        return head;
    }

    public ListNode reverseTarget(ListNode head, ListNode end){
        ListNode cur = head;
        ListNode prev = null;
        ListNode next = null;
        while(cur != null && prev != end){
            next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
        }
        //cur和next会指向需要反转的链表的后一位（在老链表中的位置）。
        if(head != null)
            head.next = cur;
        
        return prev;
    }
    
}
```