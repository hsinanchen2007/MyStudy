### 解题思路
详见代码注释

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
        ListNode temp = new ListNode(-1);
        //创建临时节点 并next指向head 
        temp.next = head;
        //prev指针用于保证current前面节点的查找
        ListNode prev = temp;
        //current指针用于遍历移动
        ListNode current = head;
        while (current != null) {
            if (current.val ==val) {
                prev.next = current.next;
            } else { prev = current;}

            current = current.next;

        }
        //保证head如果为查找值时 也能正常返回
        return temp.next;

    }
}
```