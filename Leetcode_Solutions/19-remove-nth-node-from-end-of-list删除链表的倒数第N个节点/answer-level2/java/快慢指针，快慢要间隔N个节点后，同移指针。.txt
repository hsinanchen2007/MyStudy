### 解题思路
- 快慢指针，快慢要间隔N个节点后，同移快慢指针，快指针为null时，停止移动，挂接慢指针指向next.next; 即删除了倒数节点。

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
        //创建一个辅助的哑节点指向头节点，主要处理仅有一个结点的用例。
        ListNode headRoot = new ListNode(0);
        headRoot.next = head;

        ListNode fast = headRoot;
        ListNode slow = headRoot;
        //让快节点先移动间隔N，即从1开始到n+1步。
        for(int i=1;i<=n+1;i++){
            fast = fast.next;
        }
        while(fast!=null){
            fast = fast.next;
            slow = slow.next;
        }
        // 删除慢节点指向的下一个元素，挂接新的指向。
        slow.next = slow.next.next;

    return headRoot.next;
    }
}
```