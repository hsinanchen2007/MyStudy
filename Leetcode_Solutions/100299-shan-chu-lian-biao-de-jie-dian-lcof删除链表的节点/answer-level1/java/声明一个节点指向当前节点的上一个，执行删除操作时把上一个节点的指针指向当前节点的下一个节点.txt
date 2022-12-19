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
    public ListNode deleteNode(ListNode link, int val) {
        //头节点
        ListNode head = link;

        if(head == null){
            System.out.println("链表为空");
            return head;
        }

        ListNode pre = null;
        while(link != null){
            if(link.val == val){
                if(pre != null){
                    pre.next = link.next;
                    break;
                } else {
                    head = link.next;
                    break;
                }
            }

            pre = link;
            link = link.next;
        }

        return head;
    }
}
```