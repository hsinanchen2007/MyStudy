### 解题思路
需要注意的是链表一个写不好就死循环，提交之前最好对代码流程有清晰的认识

### 代码

```cpp
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dumb = new ListNode(INT_MIN);
        dumb->next = head;
        ListNode* nexthead = head->next;
        head->next = NULL;
        head = nexthead;
        while (NULL != head) {
            ListNode* ptr = dumb;
            nexthead = head->next;
            while (NULL!=ptr->next && ptr->next->val < head->val) {
                ptr=ptr->next;
            }
            if (ptr->next == NULL) {
                ptr->next = head;
                head->next = NULL;
            }
            else {
                head->next = ptr->next;
                ptr->next = head;
            }
            head = nexthead;
        }
        return dumb->next;
    }
};
```