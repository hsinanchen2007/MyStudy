### 解题思路
向下移的指针动两下，中间节点指针动一下

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
    public ListNode middleNode(ListNode head) {
        boolean isAdd = true;
        ListNode midNode = head;
        while(head.next != null){
            if(isAdd ){
                midNode = midNode.next;
            }
            head= head.next;
            isAdd = !isAdd;
        } isAdd = !isAdd;
        
        return midNode;
    }
}
```