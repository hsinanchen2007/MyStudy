### 解题思路
prev指针和cur指针分别指向当前节点和前序节点，注意要处理删除头节点和尾节点的特殊情况。

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
    public ListNode removeElements(ListNode head, int val) {
        if (head == null) {
            return  null;
        }

        ListNode prevNode = head;
        ListNode curNode = head;
        do {

            if (curNode.val == val) {
                //头节点时
                if (prevNode == curNode) {
                    prevNode = curNode = head = head.next;
                }
                else if(curNode.next == null) {
                    prevNode.next = null;
                    curNode = null;
                }
                else {
                    prevNode.next = curNode.next;
                    curNode = curNode.next;
                    
                }
            }
            else {
                prevNode = curNode;
                curNode = curNode.next;
            }



        }while (curNode != null);



        return head;
    }
}
```