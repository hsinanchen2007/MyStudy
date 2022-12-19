```cpp
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* odd = head, *even = head->next;
        ListNode* cpy_even = head->next;
        while (odd->next) {
            odd->next = even->next;
            if (odd->next) {
                odd = odd->next;
                even->next = odd->next;
                even = even->next;
            }
        }
        odd->next = cpy_even;
        return head;
    }
};


```