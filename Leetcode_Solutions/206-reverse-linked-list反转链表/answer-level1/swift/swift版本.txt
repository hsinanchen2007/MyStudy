/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {//c++
public:
    ListNode* reverseList(ListNode* head) {
         if (head == NULL || head->next == NULL) return head;
        ListNode *p = head;
        ListNode *q = head->next;
        head->next = NULL;
        while (q) {
            ListNode *r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }
};