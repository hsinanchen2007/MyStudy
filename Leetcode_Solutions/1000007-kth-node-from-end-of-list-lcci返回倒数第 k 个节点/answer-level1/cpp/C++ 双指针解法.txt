### 解题思路
要走到倒数第k个节点，如果知道链表的长度，那么直接走长度减k步即可，如果不知道长度该怎么办？
1. 先进行遍历一遍，得出长度后按照上述步骤执行
2. 使用双指针技巧
假设我们有一个`fast`指针，令其从`head`开始先走k步，`slow`指针在链表头部不动。当`fast`指针走完k步之后，那么`slow`指针和`fast`指针一定相差k个节点。此时让两个指针都继续往下走，直到`fast`指针走到空时（最后一个节点的下一位），`slow`指针就正好停在了倒数第k个节点上，因为在向后移动的过程中，两个指针始终相差k步。
```cpp
class Solution {
   public:
    int kthToLast(ListNode *head, int k) {
        ListNode *fast = head, *slow = head;
        while (k--) fast = fast->next;
        while (fast) slow = slow->next, fast = fast->next;
        return slow->val;
    }
};
```