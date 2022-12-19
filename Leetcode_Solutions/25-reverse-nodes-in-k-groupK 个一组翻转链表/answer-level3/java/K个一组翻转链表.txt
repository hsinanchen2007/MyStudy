### 解题思路
此处撰写解题思路

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
    public ListNode reverseKGroup(ListNode head, int k) {
          if(head==null||k==1)
            return  head;
        int sum=0;
        ListNode temp=head;
        while(temp!=null){
            sum++;
            temp=temp.next;
        }
        return reverse(head,k,sum);
    }

    public ListNode reverse(ListNode head,int k,int remain)
    {
        if(remain<k)
            return head;   //剩余的链表数量不足k个，那么久不翻转
        if(head==null)
            return head;
        //正常的翻转操作
        ListNode cur=head, pre=null, last=head;
        int count=k;
        while(count-->0)
        {
            last=cur.next;
            cur.next=pre;
            pre=cur;
            cur=last;
        }
        head.next=reverse(last,k,remain-k);
        return pre;
    }
}
```