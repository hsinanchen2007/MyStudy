### 解题思路
很原始的思路，获取长度，在进行删除，注意边界。

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int size = 0;
        ListNode tmpNode = head;
        while(tmpNode != null){
            size++;
            tmpNode = tmpNode.next;
        }
        if(n <= 0 || n > size){
            return null;
        }
        if(size == n){ // 头结点删除
            head = head.next;
            return head;
        }
        tmpNode = head;
        for(int i = 1; i < (size - n); i++){
            tmpNode = tmpNode.next;
        }
        tmpNode.next = tmpNode.next.next;
        return head;
    }
}
```