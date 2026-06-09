### 方法：快慢指针

* 前言
    * 解决链表问题，一般有多种方法。最朴素的方法是，你可以借助其他数据结构，如堆栈(e.g.反转链表，回文链表)、哈希表(e.g.环形链表，相交链表，复制带random指针的链表)等等，这时候基本会使用O(N)的额外空间。
    * 如果空间复杂度限制在O(1)，那我们需要将链表掌握得更熟练，寻找更具技巧性的方法(e.g.反转链表使用尾插法这种迭代写法，回文链表反转半边再比较，环形链表用快慢指针，复制带random指针的链表可以建立weaved链表等等)，这样一来节省内存空间，但与此同时，算法不易想到，而且细节容易写错。
* 本题
    * 最简单是建立一个哈希表`visitedHash`，记录每个节点。从头开始遍历，如果遇到重复的，就返回`True`；如果指针走到底了，就返回`False`。时间复杂度：O(n); 空间复杂度: O(n)
    * 这里我使用了快慢指针`slow`和`fast`，步长分别是1和2。如果有环，二者一定会相遇，返回`True`；如果快指针走到底了，返回`False`。时间复杂度：O(n); 空间复杂度：O(1)

```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        slow, fast = head, head
        while(fast and fast.next):
            slow = slow.next
            fast = fast.next.next
            if (slow == fast):
                return True
        return False
```
```c++ []
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast)return true;
        }
        return false;
    }
};
```