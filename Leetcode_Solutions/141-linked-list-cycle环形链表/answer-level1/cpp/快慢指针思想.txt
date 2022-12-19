## 思路分析

利用快慢指针（双指针），遍历整个链表，如果存在环，快指针必然会追上慢指针，好比两个在环形跑到上跑步。

如果是存在环形，那么最好的情况下是刚好快指针遍历到最后一个节点（n）,与慢指针相遇，时间复杂度为O（N）；最差的情况下是遍历玩在遍历完最后一个节点后，再遍历到第m个节点相遇，时间复制度为O（N+M）= O (N)。

由于不利用额外空间，故空间复杂度为O（1）。

## 实现
### cpp 实现
```cpp
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
        if(head==nullptr||head->next==nullptr) return false;
        ListNode * fast = head->next, *slow = head;
        while(fast!=nullptr&&fast->next!=nullptr){
            if(fast==slow) return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};
```
### java实现
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
        if(head==null||head.next==null){
            return false;
        }
        ListNode fast = head.next, slow = head;
        while(fast!=null&&fast.next!=null){
            if(fast==slow) return true;
            fast = fast.next.next;
            slow = slow.next;
        }
        return false;
    }
}
```