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
    int temp = 0;   // temp用来表示进位
    ListNode* root = new ListNode(0);
    ListNode* current = root;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        while (l1 != NULL || l2 != NULL) {
            int sum;
            if (l1 == NULL && l2 != NULL) {
                sum = l2->val + current->val;
                l2 = l2->next;
            }
            else if (l1 != NULL && l2 == NULL) {
                sum = l1->val + current->val;
                l1 = l1->next;
            }
            else {
                sum = l1->val + l2->val + current->val;
                l2 = l2->next;
                l1 = l1->next;
            }
            if (sum > 9) {
                temp = 1;
                sum = sum % 10;
                current->val = sum;
            } else {
                current->val = sum;
            }
            if (temp) {
               current->next = new ListNode(temp);
                current = current->next;
                temp = 0;
            }
            else if ((l1 != NULL || l2 != NULL)) {
                current->next = new ListNode(temp);
                current = current->next;
                temp = 0;
            }
        }
        return root;
    }
};