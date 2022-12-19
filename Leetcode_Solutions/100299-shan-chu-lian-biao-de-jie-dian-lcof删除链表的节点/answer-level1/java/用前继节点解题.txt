### 解题思路
先设置一个前继节点，指向head，其他操作与正常删除操作一样，最后返回的时head，要查看head的val是否被删除，删除用while循环使head = head.next
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
        ListNode current = head;  //申请一个结点指向当前结点
        ListNode prev = new ListNode(0); //申请一个节点为前继节点，其next值指向head
        prev.next = head;
        while (current != null)
        {
            if(current.val == val)   //删除节点为当前节点时
            {
                prev.next = prev.next.next;
            }
            else{                    //删除节点不是当前节点时
                prev = prev.next;
            }
            current = current.next;
        }
        while(head.val == val) //因为返回的时head，所以head有删掉的话就需要调整
        {
            head = head.next;
        }
        return head;
    }
}
```