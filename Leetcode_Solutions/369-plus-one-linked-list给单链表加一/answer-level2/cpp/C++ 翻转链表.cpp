```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        prev->next = NULL;
        while (curr != NULL) {
            ListNode* node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = node;
        }
        return prev;
    }
    ListNode* plusOne(ListNode* head) {
        if (head == NULL) return new ListNode(1);
        ListNode* rhead = reverse(head);
        ListNode* node = rhead;
        ListNode* prev = node;
        int r = 1;
        while (node != NULL && r > 0) {
            r += node->val;
            node->val = r % 10;
            r /= 10;
            prev = node;
            node = node->next;
        }
        if (r > 0) {
            prev->next = new ListNode(r);
        }
        return reverse(rhead);
    }
};
```

![image.png](https://pic.leetcode-cn.com/812f2554ab2767a0d43484509ceda7a49256318e56fb788262f235c8560eb72c-image.png)
