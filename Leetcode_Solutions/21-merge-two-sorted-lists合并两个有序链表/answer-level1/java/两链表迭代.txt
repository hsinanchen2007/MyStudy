### 解题思路
比较容易想到

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null || l2==null){
            return l1==null?l2:l1;
        }
        //创建新链表的头结点
        ListNode head = new ListNode(-1);
        //创建新链表指针
        ListNode p = head;
        //比较两个链表节点的值分别添加到新链表中
        while(l1!=null && l2!=null){
            if(l1.val>l2.val){
                p.next=l2;
                l2=l2.next;
            }else{
                p.next=l1;
                l1=l1.next;
            }
            //新链表指针后移
            p=p.next;
        }
        //谁不为空补谁
        p.next = l2==null?l1:l2;
        return head.next;
    }
    }
```