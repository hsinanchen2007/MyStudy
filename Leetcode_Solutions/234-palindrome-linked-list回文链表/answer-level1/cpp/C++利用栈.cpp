C++利用栈
```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> stk;
        ListNode* node = head;
        while (node)
        {
            stk.push(node->val);
            node = node->next;
        }
        node = head;
        while (node)
        {
            if (node->val != stk.top())
            {
                return false;
            }
            stk.pop();
            node = node->next;
        }
        return true;
    }
};
```