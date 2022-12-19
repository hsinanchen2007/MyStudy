### 解题思路
别问我思路，我自己都照着官方的答案抄的。逐行逐行的理解，加注释。难受。


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

        //起始节点，0
        ListNode dummHead  = new ListNode(0);
        ListNode curr = dummHead;
        ListNode p = l1, q = l2;
        //进位标识符，起始不需要进位，所以默认0
        int carry = 0;

        while( p!=null || q != null ){
            //判断是否有值
            int x =  (p != null ) ? p.val : 0;
            int y =  (q != null ) ? q.val : 0;
            
            //求和
            int sum = carry + x + y;

            //判断是否需要进位
            carry = sum / 10;

            //第一个节点是0，下一个节点的数字。例如：当前是0，下一个节点是3，组合起来就是：03
            int number = sum % 10;
            curr.next = new ListNode(number);

            curr = curr.next;

            //链表下一个
            if( p != null ) p = p.next;
            if( q != null ) q = q.next;
        }

        //判断是否需要进位
        if( carry > 0 ){
            curr.next = new ListNode(carry);
        }
        //dummHead 本身是0，所以需要返回的是它的next节点
        return dummHead.next;

    }
}
```