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
    ListNode* getMid(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* mergeLists(ListNode* head1, ListNode* head2) {
        if (head1 == nullptr)
            return head2;
        else if (head2 == nullptr)
            return head1;
        ListNode* head = nullptr;
        if (head1->val <= head2->val) {
            head = head1;
            head->next = mergeLists(head1->next, head2);
        } else {
            head = head2;
            head->next = mergeLists(head1, head2->next);
        }
        return head;
    }
    
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* mid = getMid(head);
        ListNode* right = mid->next;
        mid->next = nullptr;
        return mergeLists(sortList(head), sortList(right));
    }
};
```
