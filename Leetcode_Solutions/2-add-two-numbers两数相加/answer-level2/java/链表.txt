### 解题思路
链表指针，注意点在于链表的返回以及 新链表的定义需要一个指针不动，用来指向求和后的数

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
        ListNode pre=new ListNode(0);
        ListNode cur=pre;
        int carry=0;
        while(l1!=null || l2!=null) //只要一个不为空就循环
        {
            int x=l1==null ? 0:l1.val;
            int y=l2==null ? 0: l2.val;
            int sum=x+y+carry;
            carry=sum/10;
            sum=sum%10;
            cur.next=new ListNode(sum);
            cur=cur.next;
            if(l1!=null)
            {
                l1=l1.next;
            }
            if(l2!=null)
            {
                l2=l2.next;
            }
        }
          if(carry==1)
           {
            cur.next=new ListNode(carry);
            } 
        return pre.next;
    }
}
```