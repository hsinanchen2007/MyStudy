### 解题思路

① 定义两个独立的节点，让前一个节点dummyHead指向后一个节点Stone。

② 不断地将 链表中的节点 插入到dummyHead的后面

③ 如果出现环形链表的话，在这个过程中，一定会再次遇见Stone。

### 代码

```java
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null){
            return false;
        }
        ListNode dummyHead = new ListNode(-1);
        ListNode stone = new ListNode(0);
        dummyHead.next = stone;
        ListNode curr = head;  // curr是待插入的节点
        ListNode t;  
        while (curr.next != null) {
            if (curr.next == stone) {  // 说明撞上了石头
                return true;
            }
            t = curr.next;  // 记录待插入节点的下一个节点
            curr.next = dummyHead.next;
            dummyHead.next = curr;
            curr = t;   // 恢复记录
        }
        return false;
    }
}
```