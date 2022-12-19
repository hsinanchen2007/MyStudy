### 解题思路
详见代码注释

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
        //不太好理解
        // if(l1 == null) {
        //     return l2;
        // } else if (l2 == null){
        //     return l1;
        // } else if ( l1.val < l2.val){
        //     l1.next = mergeTwoLists(l1.next,l2);
        //     return l1;
        // } else {
        //     l2.next = mergeTwoLists(l1,l2.next);
        //     return l2;
        // }
        //单链表迭代方法
        //构造一个空的l链表
        ListNode l = new ListNode(-1);
        //初始化链表的头指针
        ListNode prev = l;
        //循环比较l1和l2的值，谁的值小就将头指针的下一个元素插入l链表
        while(l1 != null && l2 != null){
            if (l1.val <= l2.val){
                prev.next = l1;
                l1 = l1.next;
            } else {
                prev.next = l2;
                l2 = l2.next;
            }
            //插入完成后，将链表头指针后移
            prev = prev.next;
        }
        //最终结果总有一个链表为null,因为是有序链表所有将非空的链表直接加到新链表l之后即可
        prev.next = l1 ==null ? l2:l1;
        //需要返回的链表，即为新的链表l的下一个所有元素链表，所以返回next
        return l.next;

    }
}
```