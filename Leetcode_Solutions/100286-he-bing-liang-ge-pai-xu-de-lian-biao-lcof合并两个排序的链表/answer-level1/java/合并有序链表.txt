### 解题思路
有递归法和迭代法两种，注意两个链表为空的情况，迭代法需要自己新建一个随意值的头节点，使用头插法遍历

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
        ListNode head = null;
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        if(l1.val < l2.val){//前提是两个链表都不为空
            head = l1;
            head.next = mergeTwoLists(l1.next, l2);
        }else{
            head = l2;
            head.next = mergeTwoLists(l1, l2.next);
        }
        return head;
        // ListNode head = new ListNode(-1);//必须新建一个随意值的头节点
        // ListNode pre = head;//头插法，反转链表可以使用尾插法
        // while(l1 != null && l2 != null){
        //     if(l1.val < l2.val){
        //         pre.next = l1;
        //         pre = pre.next;//pre后移
        //         l1 = l1.next;//l1后移
        //     }else{
        //         pre.next = l2;
        //         pre = pre.next;
        //         l2 = l2.next;
        //     }
        // }
        // if(l1 == null) pre.next = l2;
        // if(l2 == null) pre.next = l1;
        // return head.next;//因为头节点不存值
    }
}
```