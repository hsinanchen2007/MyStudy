将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

    输入：1->2->4, 1->3->4
    输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists

### 解题思路
按照归并排序的思路，不断遍历两个数组，取最小的值追加到链表中，在某个链表结束遍历之后，将另一个链表剩余的值拼接到新链表中。

##### Python

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(None)
        l3 = head
        while l1 and l2:
            if l1.val > l2.val:
                node = ListNode(l2.val)
                l2 = l2.next 
            else:
                node = ListNode(l1.val)
                l1 = l1.next
            l3.next = node
            l3 = l3.next
        if l1:
            l3.next = l1
        else:
            l3.next = l2 
        return head.next
```


##### Java
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
        ListNode head = new ListNode(-1);
        ListNode l3 = head;
        while(l1 != null && l2 != null){
            ListNode node = null;
            if(l1.val > l2.val){
                node = new ListNode(l2.val);
                l2 = l2.next ;
            }
            else{
                node = new ListNode(l1.val);
                l1 = l1.next;
            }
            l3.next = node;
            l3 = l3.next;
        }
        if(l1 != null)
            l3.next = l1;
        else
            l3.next = l2 ;
        return head.next;
    }
}
```