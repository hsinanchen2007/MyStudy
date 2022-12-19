### 解题思路
此处撰写解题思路
对于原有的链表，声明三个节点，prev：前节点，curr：当前操作节点，nextNode，后节点，对curr进行指针操作，并且三个节点依次向后移动，直到curr为null
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
    public ListNode reverseList(ListNode head) {
        //head头结点，后续指针改为null，获取head的后一个元素，并且将其指针改为head
        ListNode prev = null;
        ListNode curr = head;
        while(curr != null){
            ListNode nextNode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
}
```