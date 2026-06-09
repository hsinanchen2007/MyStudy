### 解题思路
首先两个链表的指针分别同时从头开始
（1）当两个链表都不为空时，让他们对应的值相加并赋值给sum（设置一个m，当sum>=10时，m=1，在下次创建节点之前，判断一下m=1?，如果为1，则本次sum++）
（2）当其中一个链表为空另一个不为空时，直接创建节点赋值就行（注意：这里也要看看是否>=10）
（3）当两个链表都为空，但是m=1时，多创建一个节点，为的就是进位
（4）最后，如果新定义的链表l3是空，则返回l3，否则返回l3.next;

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
        ListNode l3=new ListNode(0);
        ListNode head=l3;
        int m=0;
       while(l1!=null&&l2!=null)
        {
            int sum=l1.val+l2.val;
            if(m==1)
            {
                m=0;
                sum++;
            }
            if(sum>=10)
            {
                System.out.println("大于等于10，让m=1"); 
                m=1;
            }
            head.next=new ListNode(sum%10);
            head=head.next;
            l1=l1.next;
            l2=l2.next;
        }
        while(l1!=null)
        {
            int sum=l1.val;
            l1=l1.next;
            if(m==1)
            {
                sum++;
                m=0;
            }
            if(sum>=10)
            {
                m=1;
            }
            head.next=new ListNode(sum%10);
            head=head.next;
        }
        while(l2!=null)
        {
            int sum=l2.val;
            l2=l2.next;
            if(m==1)
            {
                sum++;
                m=0;
            }
            if(sum>=10)
            {
                m=1;
            }
            head.next=new ListNode(sum%10);
            head=head.next;
        }
        if(l1==null&&l2==null&&m==1)
        {
            head.next=new ListNode(1);
        }
        if(l3.next==null)
        {
            return l3;
        }
        else{
            return l3.next;
        }

    }
}
```