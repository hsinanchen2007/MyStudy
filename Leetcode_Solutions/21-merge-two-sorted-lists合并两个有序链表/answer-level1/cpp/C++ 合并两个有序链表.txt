***Talk is cheap. Show me the code.***

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        dummy.next = nullptr;
        ListNode *p = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = (l1 != nullptr ? l1 : l2);
        return dummy.next;
    }
};

```
- 类似归并排序的合并两个有序数组
- 一般来说，涉及到链表的插入、删除操作，用哨兵结点可以避免某些边界条件判断，简化代码实现