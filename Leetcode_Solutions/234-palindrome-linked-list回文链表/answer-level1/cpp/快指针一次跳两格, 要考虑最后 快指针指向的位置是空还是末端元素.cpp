解题思路:反转链表的同时,快指针往后跳.快指针指向末尾或空的时候,刚好反转了一半.

```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }

        if(fast)
        {
            head = head->next;
        }
        
        while(pre && head)
        {
            if(pre->val != head->val)
            {
                return false;
            }
            pre = pre->next;
            head = head->next;
        }

        return true;
    }
};
```
