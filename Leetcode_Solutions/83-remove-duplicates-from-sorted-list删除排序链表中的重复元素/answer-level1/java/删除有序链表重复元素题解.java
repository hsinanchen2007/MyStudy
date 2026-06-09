### 解题思路
题目分析：本题主要重点在于链表是有序的，因此链表中相同的重复元素一定是紧挨着的。
具体操作：设置两个指针，第一个指针指向当前数值下的第一个链表节点，第二个指针则用于找出和第一个指针所在节点具有相同数值的其他节点。每次遇到相同节点时则第二个指针向后一步，并将第一个指针的next节点设为第二个指针所指节点。

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
    public ListNode deleteDuplicates(ListNode head) {
        if(head==null){
            return head;
        }
        ListNode prev=head;
        ListNode next=prev.next;
        while(next!=null){
            if(prev.val==next.val){
                next=next.next;
                prev.next=next;
            }else{
                prev=next;
                next=next.next;
            }
        }
        return head;
    }
}
```