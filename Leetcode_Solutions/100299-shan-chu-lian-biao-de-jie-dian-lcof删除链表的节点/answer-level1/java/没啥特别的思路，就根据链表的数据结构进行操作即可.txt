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
    public ListNode deleteNode(ListNode head, int val) {
        if(head.val == val){
            head.val = head.next.val;
            head.next = head.next.next;
            return head;
        }

        //第一种解法，通过改变上一节点的next
        ListNode nextNode = head.next;
        ListNode preNode = head;
        while(nextNode != null){
            if(nextNode.val == val){
                preNode.next = nextNode.next;
                break;
            }
            preNode = nextNode;
            nextNode = nextNode.next;
        }

        return head;
    }
}
```