```
/**
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        # 快慢指针找链表中点
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        # 从中间断链，并把后半部分链表中的节点压入栈中
        stack<ListNode*> ptrs;
        ListNode* bg = slow->next;
        slow->next = NULL;
        while(bg)
        {
            ptrs.push(bg);
            bg = bg->next;
        }
        # 把栈中的节点依次插入
        ListNode* curr = head;
        while(curr && !ptrs.empty())
        {
            ListNode* add = ptrs.top();
            ptrs.pop();
            add->next = curr->next;
            curr->next = add;
            curr = add->next;
        }
    }
};
```
