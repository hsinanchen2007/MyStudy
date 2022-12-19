代码中 dummy 是伪节点，dummy_ptr 是伪节点指针的指针，last_inserted 是上次插入位置，head 是最终结果链表的头部。请注意两个二阶指针的使用。


```
class Solution {
public:
    struct ListState {
        ListNode dummy { INT_MAX, nullptr };
        ListNode *head = &dummy;
        ListNode **last_inserted = &head;
        ListNode **dummy_ptr = &head;
        
        void insert(ListNode *p) {
            if (p->val < (*last_inserted)->val)
                last_inserted = __insert(&head, p);
            else
                last_inserted = __insert(last_inserted, p);
        }
        
        void finalize() {
            *dummy_ptr = nullptr;
        }
    private:
        ListNode ** __insert(ListNode **head, ListNode *p) {
            while ((*head)->val < p->val)
                head = &(*head)->next;
            
            p->next = *head;
            *head = p;
            
            if (p->next == &dummy)
                dummy_ptr = &p->next;
            
            return head;
        }        
    };

    ListNode* insertionSortList(ListNode* head) {
        ListState state;
        while (head) {
            auto p = head;
            head = head->next;
            state.insert(p);
        }
        state.finalize();
        return state.head;
    }
};
```
