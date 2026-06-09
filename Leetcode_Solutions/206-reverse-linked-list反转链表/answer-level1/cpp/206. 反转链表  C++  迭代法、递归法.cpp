
```cpp
class Solution {
public:

    //迭代法
    ListNode* reverseList(ListNode* head) {

        if (head == nullptr || head->next == nullptr) 
            return head;

        ListNode* prev = nullptr;
        ListNode* cur = head;

        while (cur)
        {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        return prev;    
    }

    
    //递归法  递归函数总是返回p 即返回原链表尾结点
    ListNode* reverseList(ListNode* head) {

        if (head == nullptr || head->next == nullptr) 
            return head;

        ListNode* p = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return p;
    }
};