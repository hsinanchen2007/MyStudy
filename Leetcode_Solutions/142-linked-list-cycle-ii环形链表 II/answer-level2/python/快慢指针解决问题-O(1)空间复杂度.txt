给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

示例 1：

    输入：head = [3,2,0,-4], pos = 1
    输出：tail connects to node index 1
    解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

    输入：head = [1,2], pos = 0
    输出：tail connects to node index 0
    解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

    输入：head = [1], pos = -1
    输出：no cycle
    解释：链表中没有环。




进阶：
你是否可以不用额外空间解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii


### 解题思路
这题做完了可以去做 [287. 寻找重复数](https://leetcode-cn.com/problems/find-the-duplicate-number/)，解题思路可以参考[解题思路](https://zhuanlan.zhihu.com/p/102298178)

首先我们看下面这样一个环形的链表。题目要求寻找环形的入口。（图是盗的）

![](https://pic.leetcode-cn.com/970cf34694dd893c64924e1559617f64ad6b5b272a81ac3de5836cb6fb42fed7-image.png)

我们在设立两个快慢指针，一个走一步，一个走两步。在快的进入环之后，会不断的在环形里面绕圈子。最终它们会在某点相遇。为什么会相遇呢，设此点为p
设起点到入口为的长度为M, 入口到p的距离为P。环形的周长为c
此时 slow = M+P， fast=M+P+rc。(r为一个变量），也就是当rc = slow时，它们两个会相遇。
此时我们知道的公式为：
1. fast = 2slow
2. slow = M+P
3. fast = 2slow = M+P + slow = M+P+rc 
所以slow = rc. M = rc - P = (r-1)c + (c- P), c - P 等于从相遇的p点再走回到环的起点。

因此，我们可以得出一个结论，当在用一个指针ptr，从0开始，走M步到入口时， slow和ptr同时出发，同样走M步（(r-1)c + (c- P)) 也就是走(r-1)圈，然后在加上 c-p步，也就是从相遇到p点回到起点。正好可以和ptr在入口处相遇。

这样就能确定入口的位置

时间复杂度O(n)
空间复杂度O(1)

##### Python
```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        slow, fast = head, head 
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow is fast: ## 相遇
                break
        if not fast or not fast.next: ## 如果是正常退出则没有环
            return None
        ptr = head  ## 增加一个起点指针伴随slow同步遍历
        while slow and ptr != slow: # 相遇则是入口
            ptr = ptr.next  
            slow = slow.next
        return slow
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
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast)
                break;
        }
        if(fast == null || fast.next == null)
            return null;
        ListNode ptr = head ;
        while(slow != null && ptr != slow){
            ptr = ptr.next;
            slow = slow.next;
        }       
        return slow;
    }
}
```


##### 大佬解法
大佬通过字典（HashMap)去存储走过的节点，当节点再次出现时返回节点，如果退出循环，返回None。

时间复杂度O(n)
空间复杂度O(n)

没有用leetcode要求的O(1)空间的进阶思路解决问题，不算大佬

```python
class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: """
        if not head:
            return None
        storedict = {}
        node = head
        count = 0
        while node:
            storedict[node] = count
            node = node.next
            if node in storedict:
                return node
        return None
```