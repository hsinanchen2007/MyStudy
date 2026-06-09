### 解题思路
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
    public ListNode oddEvenList(ListNode head) {
        if(head==null)
        return null;
        ListNode p = head;
        ListNode pre = head;
        ListNode last ;
        int len = 0;
        while(p.next!=null)//找到最后一个节点和链表长度
        {
            p=p.next;
            len++;
        }
        len++;
        if(len==2)
        return head;
        last = p;
        p=head;
        int count = 1;
        while(count<=len)
        {
            if(count%2==0)//偶数节点
            {
                ListNode temp=p.next;
                pre.next = p.next;
                last.next=p;
                p = temp;
                last = last.next;
            }
            else{//奇数
                pre = p;
                p = p.next;
            }
            count++;
        }
        last.next = null;
        return head;
    }
}
```