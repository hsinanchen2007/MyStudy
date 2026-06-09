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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack <int> S1;
        stack <int> S2;
        while(l1) {
            S1.push(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            S2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* head = new ListNode(0);
        head->next = NULL;
        int temp = 0;
        while(!S1.empty()||!S2.empty()||temp) {
            int value=0;
            ListNode* q = new ListNode(0);
            if(!S1.empty()) {
                value += S1.top();S1.pop();
            }
            if(!S2.empty()) {
                value += S2.top();S2.pop();
            }
            value += temp;
            q->val = value % 10;
            q->next = head->next;
            head->next = q;
            temp = value / 10;
        }
        return head->next;
    }
    
    
};