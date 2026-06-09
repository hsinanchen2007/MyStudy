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
    ListNode* reverse(ListNode* beg, ListNode* end) {
        if (beg == end) return beg;
        auto node = beg;
        while (node->next != end) node = node->next;
        node->next = end->next;
        end->next = reverse(beg, node);
        return end;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;
        ListNode* res = NULL;
        int n = 1;
        auto end = head;
        while (end->next != NULL && n < k) {
            ++n;
            end = end->next;
        }
        if (n < k) return head;
        auto node = end->next;
        reverse(head, end);
        head->next = reverseKGroup(node, k);
        return end;
    }
};
```
![image.png](https://pic.leetcode-cn.com/a689cdd65cf78fce38ec3bf3ccfb9613ea4fb50802ffbba08577f98aa0645bbf-image.png)
