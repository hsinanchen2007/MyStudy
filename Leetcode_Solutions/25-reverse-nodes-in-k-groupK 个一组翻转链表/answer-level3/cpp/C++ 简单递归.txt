```C++ []
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int d = 0;
        auto node = head;
        while (node != NULL) {
            if (++d >= k) break;
            node = node->next;
        }
        if (d < k) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        for (int i = 0; i < k; ++i) {
            auto node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = node;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
```

![image.png](https://pic.leetcode-cn.com/7a3f82d99f9f478340d10702a480b7242852da321f0a14e3816e53471d201bd5-image.png)
