### 解题思路
此处撰写解题思路
本题难点：
1.考虑进位，如何设计进位的方式；
2.考虑两个i链表长度不等；
3.考虑有没有多余的节点；

总体思路：设置一个flag标志位指示有没有进位，如果l1与l2非空就取出它的val相加，**得到的结果与当前节点的val相加作为当前节点的val**，判断结果是否大于等于10，如果是置flag为true，当前节点的val减等10，如果flag是true，创建下一个节点（即当前节点（设为p）的next）时用p.next=new ListNode(1)，如果不为true则用p.next=new ListNode(0)；
最后找到链表的最后一个节点，如果它的val是0就把他移除，也就是它的上一个节点的next置null


这个题细节好多。。。。。
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
        if(l1==null && l2==null) return l1;

        //以下两句可有可无
        if(l1.val==0 && l1.next==null) return l2;
        if(l2.val==0 && l2.next==null) return l1;


        ListNode node=new ListNode(0);
        ListNode p=node;
        boolean flag=false;
        while(l1!=null || l2!=null)
        {
            int val1,val2;
            if(l1!=null) val1=l1.val;
            else val1=0;
            if(l2!=null) val2=l2.val;
            else val2=0;

            int val=val1+val2;
            p.val=p.val+val;
            if(p.val>=10)
            {
                flag=true;
                p.val-=10;
            }
            if(l1!=null) l1=l1.next;
            if(l2!=null) l2=l2.next;
            if(flag)
            {
                p.next=new ListNode(1);
                flag=false;
            }
            else p.next=new ListNode(0);

            p=p.next;
        }




        p=node;
        ListNode pre=null;
        while(p.next!=null)
        {
            pre=p;
            p=p.next;
        }
        if(p.val==0) pre.next=null;

        return node;
    }
}
```