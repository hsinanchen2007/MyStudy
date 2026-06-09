### 解题思路
对应链表各个节点相加，进位保存到下一次节点相加。
    注意：在最后一个相加的时候，得额外判断有没有进位产生，如果有进位，则会产生新得节点。

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
        ListNode p1 = l1;
        ListNode p2 = l2;
        ListNode result = new ListNode (0);
        ListNode p3= result;
        int count = 0;
        while(p1!=null||p2!=null)
        {
            int p1Value = (p1!=null)?p1.val:0;
            int p2Value = (p2!=null)?p2.val:0;
            int sum = p1Value+p2Value+count;
            count = sum/10;
            p3.next = new ListNode (sum%10);
            p3=p3.next;
            if(p1!=null)
                p1=p1.next;
            if(p2!=null)
                p2=p2.next;
        }
        //如果最后一位相加有溢出1，则新增一个节点存储1
        if(count>0)
        {
            p3.next = new ListNode (count);
            p3=p3.next;
        }
        result = result.next;
        return result;
    }
}
```