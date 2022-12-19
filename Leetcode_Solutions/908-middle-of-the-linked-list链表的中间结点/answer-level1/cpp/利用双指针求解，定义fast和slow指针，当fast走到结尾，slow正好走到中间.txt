![leetcode876.png](https://pic.leetcode-cn.com/3ca4ad2edd3891739ea6eafddc6db310c7d352da6a44a8efb9be5d0b80ff03ba-leetcode876.png)
```
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next == nullptr) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        int f = 1, s = 1;
        while(fast) {
            if(fast->next) f++;
            fast = fast->next;
            while(s < f / 2 + 1) {
                s++;
                slow = slow->next;
            }
        }
        return slow;
    }
};
```
