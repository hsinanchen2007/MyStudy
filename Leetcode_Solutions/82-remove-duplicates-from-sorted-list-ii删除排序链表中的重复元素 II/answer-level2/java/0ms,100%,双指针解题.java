### 解题思路
![屏幕快照 2020-03-02 18.17.44.png](https://pic.leetcode-cn.com/ecce23e245f30378e976f2ac5573666fd7420e1097753cad1fe22817b326136b-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-02%2018.17.44.png)


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
        if (head == null || head.next == null) {
            return head;
        }
        // 设置虚拟头节点
        ListNode dynamicHead = new ListNode(0);
        dynamicHead.next = head;
        // 永远是head的上一个节点，这样就可以在移除head操作上级指针
        ListNode pre = dynamicHead;
        // 标记当前head是否需要移除
        boolean remove = false;
        while (head.next != null) {
            // 当前值和下一值相等时，将当前的下一个指针指向下下个，并标记当前节点应该移除
            if (head.val == head.next.val) {
                remove = true;
                head.next = head.next.next;
            } 
            // 当前值和下一个值不相等时，并且当前节点应该移除时，操作pre.next指向当前节点下一个值（当前节点移除）
            else if (remove && head.val != head.next.val) {
                remove = false;
                pre.next = head.next;
                head = head.next;
            } else {
                // 不需要移除当前节点时，pre走动一格
                if (!remove) {
                    pre = pre.next;
                }
                head = head.next;
            }
        }
        // 如果需要移除当前节点，则pre.next置空
        if (remove) {
            pre.next = null;
        }
        return dynamicHead.next;
    }
}
```