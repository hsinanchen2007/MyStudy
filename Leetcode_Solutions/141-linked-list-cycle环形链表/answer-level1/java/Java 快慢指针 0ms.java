### 解题思路
执行用时 :0 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :38.2 MB, 在所有 java 提交中击败了91.67%的用户

**快慢指针**
两个指针遍历整个链表，其中一个走的快（走两步）,一个走的慢（走一步），如果链表有环，他们一定会相遇（这是判断的核心，可以在草稿纸上画画移动过程），
其他的逻辑就是“走步”和“判空”了。

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        
        if (head == null) return false;
        
        ListNode slow = head;
        ListNode fast = head;
        
        while (slow != null && fast != null){
        
            slow = slow.next;
            if (fast.next == null) return false;
            fast = fast.next.next;
            
            // 只要慢节点和快节点相遇 说明有环
            if (slow == fast) return true;
        }
        
        return false;
    }
}
```