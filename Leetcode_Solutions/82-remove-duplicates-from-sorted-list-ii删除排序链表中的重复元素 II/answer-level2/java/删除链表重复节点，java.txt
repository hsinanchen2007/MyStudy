### 解题思路
用三个节点标记来进行删除。

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
        ListNode pHead = null;
        ListNode preNode = null;
        ListNode curNode = head;
        while(curNode != null){
            ListNode nexNode = curNode.next;
            if(nexNode == null || nexNode.val != curNode.val){
                preNode = curNode;
            }else{
                while(nexNode != null && curNode.val == nexNode.val){
                    curNode = curNode.next;
                    nexNode = nexNode.next;
                }
                if(preNode != null)
                    preNode.next = nexNode;     
            }
            curNode = nexNode;
            
            if(pHead == null){
                pHead = preNode;
            }
        }
        return pHead;
    }
}
```