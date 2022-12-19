### 解题思路
1.双指针，使得链表所有的结点相同操作
2.定义头结点，方便返回
3.链表中的数值无相同的，找到立刻break

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
    public ListNode deleteNode(ListNode head, int val) {
        ListNode dummy = new ListNode(0);
        ListNode prev = dummy;
        prev.next = head;
        ListNode curr = head;
        while(curr!=null){
            if(curr.val == val){
                prev.next = curr.next;
                break;
            }
            else 
                prev = prev.next;
            curr = curr.next;
        }
        return dummy.next;
    }
}
```