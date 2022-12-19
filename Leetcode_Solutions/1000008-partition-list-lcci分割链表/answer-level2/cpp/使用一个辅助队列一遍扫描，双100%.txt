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
    ListNode* partition(ListNode* head, int x) {
        queue<ListNode*> q;
        ListNode* res = head;
        while(head) {
            if (head->val >= x) {
                q.push(head);
            } else {
                if (!q.empty()) {
                    std::swap(head->val, q.front()->val);
                    q.pop();
                    q.push(head);
                }
                if (!res) {
                    res = head;
                }
            }
            head = head->next;
        }
        return res;

    }
};