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
    public ListNode swapPairs(ListNode head) {
        if(head==null)return null;
        if(head.next==null)return head;
        ListNode p=head;//p指向表头
        ListNode q=p.next; //q指向表头的next
        p.next=q.next;//p和q结点实现交换
        q.next=p;
        head=q;//头指针重新指向q,方便返回结果
        while(p.next!=null){//每次循环完p指向的结点总是q.next
            q=p;//q指针指向p指针移动前的结点
            p=p.next;
            if(p.next!=null)q.next=p.next;//判断p是否到尾部，若没到尾部，
                    //让第一次交换结束后的后一结点指向第二次开始交换的后一结点
                q=p.next;//让q指向p的next
            if(p.next!=null)p.next=q.next;//判断p是否到尾部，若没到尾部，p和q结点交换
            if(q!=null)q.next=p;//防止q空指针异常
        }
        return head;
    }
}
```