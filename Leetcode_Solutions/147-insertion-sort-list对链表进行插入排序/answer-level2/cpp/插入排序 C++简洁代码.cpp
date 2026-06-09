插入排序关在在于查找，找到不大于当前元素值的最后一个位置，然后在此位置后（不能是之前）插入元素。

技巧有两点：
1. 申请dummy头节点，简化编程。
2. 查找过程中用后继节点进行比较，这样当遇到比当前节点大的时候，此时就是插入位置的前驱节点。否则需要在遍历过程中保存前驱节点。

需要注意的一点：
1. 查找位置一定要是在此之后插入，而不能是在此之前。因为在此之前的话，有可能插入位置是NULL。

```
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode header(INT_MIN);

        while (head)
        {
            ListNode* cur = head;
            head = head->next;
            ListNode* p = search(&header, cur);
            // insert node after p !
            cur->next = p->next;
            p->next = cur;
        }

        return header.next;
    }

    ListNode* search(ListNode* head, ListNode* node)
    {
        // use the next node to compare !
        while (head->next && head->next->val < node->val)
        {
            head = head->next;
        }
        return head;
    }
};
```
