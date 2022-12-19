### 解题思路
两个链表都从后面开始加：先把了l1, l2翻转了
循环重复sum=l1.val||l2.val+carryOut, carryOut = sum/10, list.next.val = sum%10的过程
注意现在得到的结果与需求结果是相反的，因为每次得到的value都放在next.val
最后再把现有的链表翻转得到想要的结果。

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode c1 = reverse(l1), c2 = reverse(l2),dummy = head;
        int sum = 0, carryOut = 0;
        while(c1!=null || c2!=null){
            int x = c1==null?0:c1.val;
            int y = c2== null?0:c2.val;
            sum = x+y+carryOut;
            carryOut = sum/10;
            dummy.next = new ListNode(sum%10);
            dummy = dummy.next;
            if(c1!=null) c1 = c1.next;
            if(c2!=null) c2 = c2.next;

        }

        if(carryOut!=0){
            dummy.next = new ListNode(carryOut);
        }

        return reverse(head.next);

    }

    //reverse list
    public ListNode reverse(ListNode node){
        if(node == null || node.next == null) return node;
        ListNode cur = reverse(node.next);
        node.next.next = node;
        node.next = null;
        return cur;
        
    }
}
```