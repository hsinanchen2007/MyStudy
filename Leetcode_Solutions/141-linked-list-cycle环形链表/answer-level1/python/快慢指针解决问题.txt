给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

 

示例 1：

    输入：head = [3,2,0,-4], pos = 1
    输出：true
    解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

    输入：head = [1,2], pos = 0
    输出：true
    解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

    输入：head = [1], pos = -1
    输出：false
    解释：链表中没有环。


 

进阶：

你能用 O(1)（即，常量）内存解决此问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle




### 解题思路
#### 约瑟夫环
解决约瑟夫环有一个定理。 两个人在一个圈走，只要速度不同，最终总会相遇。

我们在设立两个快慢指针，一个走一步，一个走两步。在快的进入环之后，会不断的在环形里面绕圈子。最终它们会在某点相遇。为什么会相遇呢，设此点为p
设起点到入口为的长度为M, 入口到p的距离为P。环形的周长为c
此时 slow = M+P， fast=M+P+rc。(r为一个变量），也就是当rc = slow时，它们两个会相遇。

所以我们可以设定快慢指针遍历判断，如果没有环形，它们最终会走到尾指针为None,如果有环形，我们只要判断两个指针是否相遇，如果相遇就结束循环。

相遇所走的步数（循环次数）等于 M + P. P等于 c - M % c (第一次相遇)

时间复杂度 O(n)
空间复杂度 O(1)


##### Python
```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head is None or head.next is None:
            return False
        slow, fast = head.next, head.next.next
        while fast and fast.next:
            if slow is fast:
                return True
            slow = slow.next
            fast = fast.next.next
        return False
```


##### Java
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
        if(head == null || head.next == null)
            return false;
        ListNode slow =  head.next; 
        ListNode fast = head.next.next;
        while(fast != null && fast.next != null){
            if(slow == fast)
                return true;
            slow = slow.next;
            fast = fast.next.next;
        }
        return false; 
    }
}
```